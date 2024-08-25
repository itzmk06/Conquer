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

int main(){
    Node* first=new Node(10);
    Node* second=new Node(20);
    Node* third=new Node(30);
    Node* fourth=new Node(40);
    Node* fifth=new Node(50);

    first->next=second;
    second->prev=first;
    second->next=third;
    third->prev=second;
    third->next=fourth;
    fourth->prev=third;
    fourth->next=fifth;
    fifth->prev=fourth;
    
    
    print(first);

    return 0;
}