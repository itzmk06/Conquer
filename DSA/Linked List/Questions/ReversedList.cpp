// * Optimal 
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
class Solution {
public:
    ListNode* reverseLL(ListNode* head){

        ListNode* curr=head;
        ListNode* prev=NULL;
        while(curr!=NULL){
            ListNode* forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        if(head==NULL||head->next==NULL||head->next->next==NULL){
            return;
        }
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast&&fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* middle=slow;
        ListNode* rev=reverseLL(middle->next);
        middle->next=NULL;
        ListNode* curr=head;
        ListNode* rever=rev->next;
        ListNode* temper=curr->next;
        while(rev!=NULL){
            temper=curr->next;
            rever=rev->next;
            curr->next=rev;
            rev->next=temper;
            curr=temper;
            rev=rever;
        }
    }
};

//* Brute but better run time but O(N) both time and space complexity 
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
class Solution {
public:
    void reorderList(ListNode* head) {
        stack<ListNode*>st;
        ListNode* temp=head;
        
        int count=0;
        
        while(temp!=NULL){
            count++;
            st.push(temp);
            temp=temp->next;
        }

        int k=count/2;

        ListNode* curr=head;
        while(k>0){
                ListNode* temper=curr->next;
                ListNode* last=st.top();
                st.pop();
                curr->next=last;
                last->next=temper;
                curr=temper;
            k--;
        }
            curr->next=NULL;
    }
};