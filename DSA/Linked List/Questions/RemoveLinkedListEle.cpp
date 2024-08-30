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
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL){
            return NULL;
        }
        ListNode* prev=head;
        ListNode* temp=head;
        while(temp!=NULL){
            if(temp->val!=val){
                prev=temp;
                temp=temp->next;
            }else{
                prev->next=temp?temp->next:NULL;
                temp=temp->next;
            }

        }
        if(head->val==val){
            ListNode* ptr=head;
            head=head->next?head->next:NULL;
            delete ptr;            
        }
        return head;
    }
};