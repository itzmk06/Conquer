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

Node* reverseNodes(Node* head){
    Node* prev=NULL;
    Node* curr=head;
    while(curr!=NULL){
        Node* forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
    }
    return prev;
}


bool checkPalindrome(Node* head){
    //when LL is empty 
    if(head==NULL){
        return true;
    }
    if(head->next==NULL){
    // when LL has only one node 
        return true;
    }
    // more than one node is present 
    // find the first middle node 
    Node* slow=head;
    Node* fast=head->next;
    while(fast!=NULL){
        if(fast!=NULL){
            fast=fast->next;
        }
        if(fast!=NULL){
            fast=fast->next;
            slow=slow->next;
        }
    }
    // now slow is our middle element 
    // we have to sort the nodes after the middle element 
    slow->next=reverseNodes(slow->next);


    // take pointers in both of LL and compare them 
    Node* temp1=head;
    Node* temp2=slow->next;
    // run the loop till the values pointed by both the pointers are same 
    while(temp2!=NULL){
        if(temp1->data==temp2->data){
            temp1=temp1->next;
            temp2=temp2->next;
        }else{
            return false;
        }
    }
    return true;
}

int main(){
    Node* first=new Node(10);
    Node* second=new Node(20);
    Node* third=new Node(30);
    Node* fourth=new Node(40);
    Node* fifth=new Node(30);
    Node* sixth=new Node(20);
    Node* seventh=new Node(10);

    first->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=fifth;
    fifth->next=sixth;
    sixth->next=seventh;

    bool result=checkPalindrome(first);
    print(first);
    cout<<"Palindrome is present: "<<result<<endl;
    


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
//         ListNode* reverseNodes(ListNode* head){
//         ListNode* prev=NULL;
//         ListNode* curr=head;
//         while(curr!=NULL){
//             ListNode* forward=curr->next;
//             curr->next=prev;
//             prev=curr;
//             curr=forward;
//         }
//         return prev;
//     }
//     bool isPalindrome(ListNode* head) {
//         if(head==NULL){
//             return true;
//         }
//         if(head->next==NULL){
//             return true;
//         }
//         ListNode* slow=head;
//         ListNode* fast=head->next;
//         while(fast!=NULL){
//             if(fast!=NULL){
//                 fast=fast->next;
//             }
//             if(fast!=NULL){
//                 fast=fast->next;
//                 slow=slow->next;
//             }
//         }
//         slow->next=reverseNodes(slow->next);
//         ListNode* temp1=head;
//         ListNode* temp2=slow->next;
//         while(temp2!=NULL){
//             if(temp1->val==temp2->val){
//                 temp1=temp1->next;
//                 temp2=temp2->next;
//             }else{
//                 return false;
//             }
//         }
//         return true;
            
//         }
// };