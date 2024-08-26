//* Reverse in k groups 

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

Node* reverseKGroup(Node* head,int k){
    if(head==NULL){
        // ll is empty 
        return NULL;
    }
    if(head->next==NULL){
        // ll has one element 
        return head;
    }
    if(k>getLength(head)){
        // ll is smaller than k 
        return head;
    }
    // ll length is >=k 
    Node* prev=NULL;
    Node* curr=head;
    int count=0;
    Node* forward=curr->next;
    while(count<k){
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
        count++;
    }
    if(forward!=NULL){
    head->next=reverseKGroup(forward,k);
    }
        return prev;

}



//* optimized -> slow fast pointer (tortoise algo)


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
    cout<<endl;
    head=reverseKGroup(head,6);
    print(head);


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
//     int getLength(ListNode* head){
//         ListNode* temp=head;
//         int count=0;
//         while(temp!=NULL){
//             count++;
//             temp=temp->next;
//         }
//         return count;
//     }
//     ListNode* reverseKGroup(ListNode* head, int k) {
//         if(head==NULL){
//             return NULL;
//         }
//         if(head->next==NULL){
//             return head;
//         }
//         if(k>getLength(head)){
//             return head;
//         }
//         ListNode* prev=NULL;
//         ListNode* curr=head;
//         ListNode* forward=curr->next;
//         int count=0;
//         while(count<k){
//             forward=curr->next;
//             curr->next=prev;
//             prev=curr;
//             curr=forward;
//             count++;
//         }
//         if(forward!=NULL){            
//         head->next=reverseKGroup(forward,k);
//         }
//         return prev;
//     }
// };