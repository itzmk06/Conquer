//*Doubly linked list 

#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node* prev;
        Node(){
            this->data=0;
            this->next=NULL;
            this->prev=NULL;
        }
        Node(int data){
            this->data=data;
            this->next=NULL;
            this->prev=NULL;
        }
        ~Node(){
            cout<<"\nValue with data "<<this->data<<" is deleted\n";
        }
};

void print(Node* head){
    Node* temp=head;
    cout<<"\nData are as follows:\n";
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int getLength(Node* head){
    int count=0;
    Node* temp=head;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
}

//* steps to insert at beg 
// create a new node 
// make new node to point to head
// make head prev to point to new node 
// make new node as head
void insertBeg(Node* &head,Node* &tail,int data){
    if(head==NULL){
        // ll is empty
        Node* newNode=new Node(data);
        head=tail=newNode;
    }else{
        // ll is non empty
        Node* newNode=new Node(data);
        newNode->next=head;
        head->prev=newNode;
        head=newNode;
    }
}

//* steps for insert at tail 
// create a new node 
// make the new node prev to point to tail 
// make the tail next to point to new node 
// make the new node as tail 

void insertTail(Node* &head,Node* &tail,int data){
    if(head==NULL){
        // ll is empty
        Node* newNode=new Node(data);
        head=tail=newNode;
    }else{
        // ll is non empty 
        Node* newNode=new Node(data);
        newNode->prev=tail;
        tail->next=newNode;
        tail=newNode;
    }
}

// * steps to insert at pos 
// create a new node 
// get the prev node 
// get the curr node 
// make the new node prev to point to prev node
// make the prev node next to point to new node 
// make the new node next to point to curr node
// make the new node prev to point to new node 

void insertAtPos(Node* &head,Node* &tail,int pos,int data){
    if(head==NULL){
    // handle null case 
        Node* newNode=new Node(data);
        head=tail=newNode;
        return;
    }else if(pos==1){
    // handle insert at beg 
            insertBeg(head,tail,data);
            return;
    }else if (pos>getLength(head)){
        // handle insert at tail 
        insertTail(head,tail,data);
    }else{
    // handle insert at pos 
        int count=1;
        Node* prevNode=head;
        while(count<pos-1){
            prevNode=prevNode->next;
            count++;
        }
        Node* newNode=new Node(data);
        Node* curr=prevNode->next;
        prevNode->next=newNode;
        newNode->prev=prevNode;
        newNode->next=curr;
        curr->prev=newNode;
    }
}

void deletePos(Node* &head,Node* &tail,int pos){
    if(head==NULL){
        //handle when linked list is empty 
        cout<<"\nLinked list is empty!\n";
        return;
    }else if(head->next==NULL){
        // handle when linked list has only one element 
        Node* temp=head;
        delete temp;
        head=tail=NULL;
    }else if (pos==1){
        // handle deletion at beg 
        Node* temp=head;
        head=head->next;
        head->prev=NULL;
        temp->next=NULL;
        delete temp;
    }else if(pos==getLength(head)){
        // handle deletion at end 
        Node* temp=tail;
        tail=tail->prev;
        tail->next=NULL;
        temp->prev=NULL;
        delete temp;
    }else{
        // handle at middle any position 
        int count=1;
        Node* left=head;
        while(count<pos-1){
            left=left->next;
            count++;
        }
        Node* curr=left->next;
        Node* right=curr->next;
        left->next=right;
        right->prev=left;
        curr->prev=NULL;
        curr->next=NULL;
        Node * temp=curr;
        delete curr;
    }
}

int main(){
    Node* head=NULL;
    Node* tail=NULL;
    insertBeg(head,tail,10);
    insertBeg(head,tail,20);
    insertBeg(head,tail,30);
    insertTail(head,tail,40);
    insertTail(head,tail,50);
    insertTail(head,tail,60);
    insertTail(head,tail,70);
    insertAtPos(head,tail,1,100);
    print(head);
    deletePos(head,tail,8);
    print(head);

    return 0;
}