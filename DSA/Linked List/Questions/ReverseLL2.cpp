// *BruteForce 

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
    ListNode* reverse(ListNode* &head){
        ListNode* prev=NULL;
        ListNode* curr=head;
        while(curr!=NULL){
            ListNode* forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==NULL||head->next==NULL){
            return head;
        }
        ListNode* newNode=new ListNode(-1);
        ListNode* temp=head;
        ListNode* ptr=newNode;
        int count=1;
        while(count<left&&temp!=NULL&&newNode!=NULL){
            ptr->next=new ListNode(temp->val);
            ptr=ptr->next;
            temp=temp->next;
            count++;
        }
        ListNode* dummy1=new ListNode(-1);
        ListNode* d1=dummy1;
        while(count>=left&&count<=right&&temp!=NULL){
            d1->next=new ListNode(temp->val);
            d1=d1->next;
            temp=temp->next;
            count++;
        }


        ListNode* deleter=dummy1;
        dummy1=dummy1->next;
        dummy1=reverse(dummy1);

        ListNode* d3=dummy1;
        while(d3->next!=NULL){
            d3=d3->next;
        }
        while(temp!=NULL){
            d3->next=new ListNode(temp->val);
            d3=d3->next;
            temp=temp->next;
        }        

        ListNode* p1=newNode;
        while(p1->next!=NULL){
            p1=p1->next;
        }
        p1->next=dummy1;


            return newNode->next;
    }
};