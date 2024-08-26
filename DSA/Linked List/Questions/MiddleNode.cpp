//* find middle node 

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

// * Brute force 
int getLength(Node* head){
    int count=0;
    Node* temp=head;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    } 
    return count;
}

Node* midNode(Node* head){
    int len=getLength(head);
    if(head==NULL){
        // handle when no nodes 
        return head;
    }
    if(head->next==NULL){
        // handle when one node 
        return head;
    }
    // handle when greater than one node 
    if (len%2==0){
        //handle when even nodes 
        int pos=len/2;
        int count=1;
        Node* temp=head;
        while(temp!=NULL&&count<pos){
            count++;
            temp=temp->next;
        }
        return temp;
    }else{
        // handle when odd nodes
        int pos=(len/2)+1;
        int count=1;
        Node* temp=head;
        while(temp!=NULL&&count<pos){
            count++;
            temp=temp->next;
        }
        return temp;
    }
}

//* optimized -> slow fast pointer (tortoise algo)
Node* slowFast(Node* head){
    // handle for no nodes 
    if(head==NULL){
        return head;
    }
    // handle for one node 
    if(head->next==NULL){
        return head;
    }
    // handle for more than one node 
    Node* slow=head;
    Node* fast=head;
    while(fast!=NULL&&fast->next!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
            slow=slow->next;
        }
    }
    return slow;

}



int main(){
    Node* head=NULL;
    Node* tail=NULL;
    Node* first=new Node(10);
    Node* second=new Node(20);
    Node* third=new Node(30);
    Node* fourth=new Node(40);
    Node* fifth=new Node(50);
    Node* sixth=new Node(60);
    // Node* seventh=new Node(70);
    first->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=fifth;
    fifth->next=sixth;
    // sixth->next=seventh;
    head=tail=first;
    print(head);
    Node* temp=midNode(head);
    cout<<temp->data;
    cout<<endl;
    Node* ptr=slowFast(head);
    cout<<ptr->data;


    return 0;
}

//* submitted code 

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// class Solution {
// public:
//     ListNode* middleNode(ListNode* head) {
//         ListNode* fast=head;
//         ListNode* slow=head;
//         while(slow!=NULL&&fast!=NULL){
//             fast=fast->next;
//             if(fast!=NULL){
//                 fast=fast->next;
//                 slow=slow->next;
//             }
//         }
//         return slow;
//     }
// };