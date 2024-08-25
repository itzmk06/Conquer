#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node(){
            this->data=0;
            this->next=NULL;
        }
        Node(int data){
            this->data=data;
            this->next=NULL;
        }
        ~Node(){
            cout<<"\nDelete node with data :"<<this->data<<endl;
        }
};

//* Inserting first 
// create a new node 
// make the new node to point to first node 
// make the new node as first node 

void insertFirst(Node* &head,Node* &tail,int data){
    Node* newNode=new Node(data);
    if(head==NULL){
        head=tail=newNode;
        return;
    }else{
        newNode->next=head;
        head=newNode;
    }
}

// *steps for insert end 
// create a new node 
// make the tail to point to next node 
// make the new node as tail 

void insertEnd(Node*&head,Node*&tail,int data){
    Node* newNode=new Node(data);
    if(head==NULL){
        head=tail=newNode;
        return;
    }else{
        tail->next=newNode;
        tail=newNode;
    }
}

int getLength(Node* head){
    int count=0;
    Node* temp=head;
    while(temp!=NULL){
        temp=temp->next;
        count++;
    }
    return count;
}


// * steps to insert at any position (1-n)
//handle null case 

void insertPos(Node* &head,Node* &tail,int pos,int data){
    //handling when no data is inserted 
    if(head==NULL){
        Node* newNode=new Node(data);
        head=tail=newNode;
    }else if (pos==0){
        //handle when inserting to first position
        insertFirst(head,tail,data);
    }else if(pos>=getLength(head)){
        //handle when inserting to last position
        insertEnd(head,tail,data);
    }else{
        //handle when inserting in between 
        int count=0;
        Node* curr=head;
        Node* prev=head;
        while(pos!=count){
            prev=curr;
            curr=curr->next;
            count++;
        }
        Node* newNode=new Node(data);
        newNode->next=curr;
        prev->next=newNode;
    }
}

//* steps to delete beg data 
// take a ref pointer to head
// move head to point to next node 
// make ref pointer to point null 
// delete ref pointer 
void deleteBeg(Node* &head,Node* &tail){
    if(head==NULL){
        cout<<"\nLinked list is empty!\n";
        return;
    }else{
        Node* temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }
}

// * steps to delete at end 
// get a prev reference 
// get a current reference
// make prev to point to null
// get temp pointer to curr
// delete that temp pointer 
// set temp to prev

void deleteEnd(Node* &head,Node*&tail){
    if(head==NULL){
        cout<<"\nLinked list is empty!"<<endl;
        return;
    }else{
        int i=1;
        Node* prev=head;
        while(i<getLength(head)-1){
            prev=prev->next;
            i++;
        }
        Node* curr=prev->next;
        prev->next=NULL;
        Node* temp=tail;
        tail=prev;
        delete temp;
    }
}

void deletePos(Node* &head,Node* &tail, int pos){
    if(head==NULL){
        cout<<"\nLinked list is empty!"<<endl;
        return;
    }
    if(pos==1){
        deleteBeg(head,tail);
        return;
    }else if(pos>=getLength(head)){
        deleteEnd(head,tail);
    }else{
        Node* prev=head;
        Node* curr=head;
        Node* temp=head;
        int count=1;
        while(count<pos-1){
            prev=prev->next;
            count++;
        }
        curr=prev->next;
        prev->next=curr->next;
        curr->next=NULL;
        temp=curr;
        delete temp;
    }
}

void print(Node* head){
    Node* temp=head;
    cout<<endl<<"Data are as follows:"<<endl;
    while(temp!=NULL){
        cout<<temp->data<<"  ";
        temp=temp->next;
    }
}

Node* reverse(Node* prev,Node* curr){
    while(curr!=NULL){
        Node* forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
    }
    return prev;
}


int main(){
    Node* head=NULL;
    Node* tail=NULL;
    insertEnd(head,tail,10);
    insertEnd(head,tail,20);
    insertEnd(head,tail,30);
    insertEnd(head,tail,40);
    insertEnd(head,tail,50);
    insertEnd(head,tail,60);
    print(head);
    Node* prev=NULL;
    Node* curr=head;
    head=reverse(prev,curr);


    print(head);
    return 0;
}