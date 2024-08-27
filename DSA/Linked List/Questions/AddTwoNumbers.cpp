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

Node* reverse(Node* head){
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

Node* addNumbers(Node* &number1,Node* &number2){
    // if number 1 is empty
    if(number1==NULL&&number2==NULL){
        return NULL;
    }
    if(number1==NULL){
        return number2;
    }
    if(number2==NULL){
        return number1;
    }
    
    // reverse the numbers so that we add 
    // from left to right 
    number1=reverse(number1);
    number2=reverse(number2);
    // cout<<"This is number 1:"<<endl;
    // print(number1);
    // cout<<"This is number 2:"<<endl;
    // print(number2);
    
    // we have to add it from left to right 
    // maintain a carry variable 
    int carry=0;
    int d=0;
    // get the pointers to access the data from both the LL 
    Node* n1=number1;
    Node* n2=number2;

    // maintain a answer list 
    Node* sum=NULL;
    Node* sum_tail=NULL;
    // iterate till both have values ->equal node condition 
    while(n1!=NULL&&n2!=NULL){
        //addition logic 
        int result=n1->data+n2->data+carry;
        // get the digit 
        d=result%10;
        carry=result/10;
        // add the digit 
        Node* digit=new Node(d);
        if(sum==NULL){
            sum=sum_tail=digit;
        }else{
            sum_tail->next=digit;
            sum_tail=digit;
        }
        n1=n1->next;
        n2=n2->next;
    // working 
    }
    
    // handle for case when first number is present second completed 
    while(n1!=NULL){
        int result=n1->data+carry;
        int d=result%10;
        int carry=d/10;

        Node* digit=new Node(d);
        if(sum==0){
            sum=sum_tail=digit;
        }else{
            sum_tail->next=digit;
            sum_tail=digit;
        }
        n1=n1->next;
        // working
    }
    // handle for case when second node is present first completed
    while(n2!=NULL){
        int result=n2->data+carry;
        int d=result%10;
        int carry=d/10;

        Node* digit=new Node(d);
        if(sum==0){
            sum=sum_tail=digit;
        }else{
            sum_tail->next=digit;
            sum_tail=digit;
        }
        n2=n2->next;
        // working
    }
    while(carry!=0){
        int result=carry;
        int d=result%10;
        carry=carry/10;
        Node* digit=new Node(d);
        if(sum==NULL){
            sum=sum_tail=digit;
        }else{
            sum_tail->next=digit;
            sum_tail=digit;
        }
        //working 
    }
    sum=reverse(sum);
    return sum;
}




int main(){
    // Node* n1=new Node(9);
    // Node* n2=new Node(9);
    // Node* n3=new Node(9);
    // n1->next=n2;
    // n2->next=n3;
    Node* n1=NULL;
    // Node* m1=new Node(9);
    // Node* m2=new Node(9);
    // Node* m3=new Node(9);
    // m1->next=m2;
    // m2->next=m3;
    Node* m1=NULL;

    // print(n1);
    // print(m1);

    Node* sum=addNumbers(n1,m1);

    print(sum);


    return 0;
}


// * submitted code 

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
//     inline void insertAtTail(ListNode* &ans,ListNode* &ans_tail,ListNode* &digit){
//         if(ans==NULL){
//             ans=ans_tail=digit;
//         }else{
//             ans_tail->next=digit;
//             ans_tail=digit;
//         }
//     }


//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         if(l1==NULL){
//             return l2;
//         }
//         if(l2==NULL){
//             return l1;
//         }        
//         int carry=0;
//         ListNode* n1=l1;
//         ListNode* n2=l2;
//         ListNode* ans=NULL;
//         ListNode* ans_tail=NULL;
//         while(n1!=NULL&&n2!=NULL){
//             int sum=n1->val+n2->val+carry;
//             int d=sum%10;
//             carry=sum/10;
//             ListNode* digit=new ListNode(d);
//             insertAtTail(ans,ans_tail,digit);
//             n1=n1->next;
//             n2=n2->next;
//         }
//         while(n1!=NULL){
//             int sum=n1->val+carry;
//             int d=sum%10;
//             carry=sum/10;
//             ListNode* digit=new ListNode(d);
//             insertAtTail(ans,ans_tail,digit);
//             n1=n1->next;
//         }
//         while(n2!=NULL){
//             int sum=n2->val+carry;
//             int d=sum%10;
//             carry=sum/10;
//             ListNode* digit=new ListNode(d);
//             insertAtTail(ans,ans_tail,digit);
//             n2=n2->next;
//         }
//         while(carry!=0){
//             int sum=carry;
//             int d=sum%10;
//             carry=carry/10;
//             ListNode* digit=new ListNode(d);
//             insertAtTail(ans,ans_tail,digit);
//         }
//         return ans;

//     }
// };