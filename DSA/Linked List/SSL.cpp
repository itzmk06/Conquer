//* Steps for printing  ssl 
// print the data 
// make the pointer to point to next node 
// stop when the pointer points to null

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

void print(Node* &head){
    Node* temp=head;
    cout<<"Printing data:"<<endl;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}


int main(){
    //create the nodes
    Node *first=new Node(10);
    Node *second=new Node(20);
    Node *third=new Node(30);
    Node *fourth=new Node(40);
    Node *fifth=new Node(50);

    //link the nodes to one another 
    first->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=fifth;
    fifth->next=NULL;

    print(first);

    return 0;
}