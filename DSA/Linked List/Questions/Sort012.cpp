//will solve this optimally again later 

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
};

void print(Node* head){
    if(head==NULL){
        cout<<"\nLinked list is empty!"<<endl;
    }else{
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
}

Node* sort012(Node* &head){
    if(head==NULL){
        return NULL;
    }
    if(head->next==NULL){
        return head;
    }
    int count0=0;
    int count1=0;
    int count2=0;

    Node* temp=head;
    while(temp!=NULL){
        if(temp->data==0){
            count0++;
            temp=temp->next;
        }else if(temp->data==1){
            count1++;
            temp=temp->next;
        }else if(temp->data==2){
            count2++;
            temp=temp->next;

        }
    }
    temp=head;
    while(count0--){
        temp->data=0;
        temp=temp->next;
    }
    while(count1--){
        temp->data=1;
        temp=temp->next;
    }
    while(count2--){
        temp->data=2;
        temp=temp->next;
    }
    return head;

}



//1:38

int main(){
    Node* first=new Node(2);
    Node* second=new Node(2);
    Node* third=new Node(2);
    Node* fourth=new Node(2);
    Node* fifth=new Node(2);

    first->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=fifth;

    print(first);

    first=sort012(first);
    print(first);


    return 0;
}
