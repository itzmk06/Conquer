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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL){
            return list2;
        }
        if(list2==NULL){
            return list1;
        }
        ListNode* l1=list1;
        ListNode* l2=list2;
        ListNode* ans=new ListNode(-1);
        ListNode* a1=ans;
        while(l1&&l2){
            if(l1->val<=l2->val){
                a1->next=l1;
                a1=l1;
                l1=l1->next;
            }else{
                a1->next=l2;
                a1=l2;
                l2=l2->next;
            }
        }
        if(l1==NULL){
            a1->next=l2;
            a1=l2;
        }
        if(l2==NULL){
            a1->next=l1;
            a1=l1;
        }
        ListNode* temp=ans;
        ans=ans->next;
        temp->next=NULL;
        delete temp;
        return ans;
    }
};