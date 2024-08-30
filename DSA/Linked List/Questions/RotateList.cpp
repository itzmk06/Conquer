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
    int getLength(ListNode* head){
        int count=0;
        ListNode* temp=head;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        return count;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL){
            return NULL;
        }
        int len=getLength(head);
        int actualk=k%len;
        if(actualk==0){
            return head;
        }
        int newTailPos=len-actualk-1;
        ListNode* tail=head;
        while(newTailPos--&&newTailPos>=0){
            tail=tail->next;
        }
        ListNode* newHead=tail?tail->next:NULL;
        tail->next=NULL;
        ListNode* temp=newHead;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=head;


        return newHead;

    }
};