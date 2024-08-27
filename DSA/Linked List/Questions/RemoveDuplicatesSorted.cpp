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

Node* removeDuplicates(Node* &head){
    if(head==NULL){
        return NULL;
    }
    if(head->next==NULL){
        return head;
    }
    Node* temp=head;
    while(temp!=NULL){
        if(temp!=NULL&&temp->next!=NULL){
            if(temp->data!=temp->next->data){
                temp=temp->next;
            }else{
                if(temp->next->next!=NULL){
                    temp->next=temp->next->next;
                }else{
                    temp->next=NULL;
                }
            }
        }else{
            return head;
        }
    }


}

//49:38


int main(){
    Node* first=new Node(1);
    Node* second=new Node(1);
    Node* third=new Node(2);
    Node* fourth=new Node(3);
    Node* fifth=new Node(3);

    first->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=fifth;


    print(first);
    Node* cleaned_data=removeDuplicates(first);
    print(cleaned_data);


    return 0;
}