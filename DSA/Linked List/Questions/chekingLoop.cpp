//* Cycle present or not in LL

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

int getLength(Node* head){
    int count=0;
    Node* temp=head;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    } 
    return count;
}

//* optimized -> slow fast pointer (tortoise algo)
int cyclePresent(Node* head){
    if(head==NULL){
        return false;
    }
    if(head->next==NULL){
        return false;
    }
    Node* slow=head;
    Node* fast=head;
    while(fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
            slow=slow->next;
        }
        if(fast==slow){
            return true;
        }
    }
    return false;
}

int main(){
    Node* n1=new Node(10);
    Node* n2=new Node(20);
    Node* n3=new Node(30);
    Node* n4=new Node(40);
    Node* n5=new Node(50);
    Node* n6=new Node(60);
    Node* n7=new Node(70);

    n1->next=n2;
    n2->next=n3;
    n3->next=n4;
    n4->next=n5;
    n5->next=n6;
    n6->next=n7;
    // n7->next=n4;

    // print(n1);  this will cause a loop 

    int result=cyclePresent(n1);
    cout<<"\nCycle is present: "<<result<<endl;


    return 0;
}

//* submitted code 
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// class Solution {
// public:
//     bool hasCycle(ListNode *head) {
//         ListNode* slow=head;
//         ListNode* fast=head;
//         while(fast!=NULL){
//             if(fast!=NULL){
//                 fast=fast->next;
//             }

//             if(fast!=NULL){
//                 fast=fast->next;
//                 slow=slow->next;
//             }
//             if(fast==slow){
//                     return true;
//                 }
//         }
//         return false;
//     }
// };