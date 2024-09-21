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