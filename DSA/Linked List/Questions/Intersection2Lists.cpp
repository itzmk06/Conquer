/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int getLength(ListNode* head){
        ListNode* temp=head;
        int count=0;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        return count;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL||headB==NULL){
            return NULL;
        }
        int alen=getLength(headA);
        int blen=getLength(headB);
        if(alen>blen){
        int skipping=alen-blen;
            while((skipping--)&&skipping>=0){
                headA=headA->next;
            }
        }else if(blen>alen){
        int skipping=blen-alen;
            while((skipping--)&&skipping>=0){
                headB=headB->next;
            }
        }
        ListNode* a=headA;
        ListNode* b=headB;
        while(a!=NULL&&b!=NULL){
            if(a==b){
                return a;
            }
            a=a->next;
            b=b->next;
        }
        return NULL;
    }
};