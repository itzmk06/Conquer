// * Mine brute force 
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
        ListNode* temp=head;
        int count=0;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        return count;
    }
    ListNode* swapNodes(ListNode* head, int k) {
        
        ListNode* curr1=head;
        ListNode* curr2=head;
        ListNode* temp=head;
        int n=getLength(head);
        int forward=k;
        int backward=k==1?n:n-k+1;
        int count=1;
        while(temp!=NULL){
            if(count==forward){
                curr1=temp;
            }
            if(count==backward){
                curr2=temp;
            }
            temp=temp->next;
            count++;
        }
        int temp1=curr1->val;
        curr1->val=curr2->val;
        curr2->val=temp1;    

        return head;


        
    }
};

// * Micks

