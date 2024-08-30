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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL){
            return NULL;
        }
        if(head->next==NULL&&n==1){
            return NULL;
        }
        int len=getLength(head);
        int index=len-n;
        if(index==0){
            head=head->next;
            return head;
        }

        ListNode* temp=head;
        ListNode* ptr=head;
        while(index--&&index>=0){
            ptr=temp;
            temp=temp->next;
        }
        ListNode* deleter=temp;
        ptr->next=temp->next;
        return head;



        
    }
};