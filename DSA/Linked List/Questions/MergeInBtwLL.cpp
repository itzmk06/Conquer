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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* prev1 =list1;
        ListNode* prev2=list2;
        ListNode* curr1=list1;
        ListNode* curr2=list2;

        // traversing whole list 1 to set pointers 
        int count1=0;
        int count2=0;
        ListNode*temp=list1;
        while(temp!=NULL){
            count1++;
            count2++;
            temp=temp->next;
            if(count1+1==a){                
                prev1=temp;
            }
            if(count2-1==b){
                curr2=temp;
            }
        }
        prev1->next=list2;
        temp=list2;
        while(temp!=NULL){
            prev2=temp;
            temp=temp->next;
        }
        prev2->next=curr2;

        return list1;



    }
};