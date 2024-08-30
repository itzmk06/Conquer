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
    stack<ListNode*>st;
    ListNode* removeNodes(ListNode* head) {
        ListNode* curr=head;
        while(curr!=NULL){
            st.push(curr);
            curr=curr->next;
        }
        ListNode* resultNode=st.top();
        st.pop();
        int maxVal=resultNode->val;
        while(!st.empty()){
            ListNode* temp=st.top();
            st.pop();
            if(temp->val<maxVal){
                continue;
            }else{
                ListNode* newNode=new ListNode(temp->val);
                newNode->next=resultNode;
                resultNode=newNode;
                maxVal=newNode->val; 
            }

        }
        return resultNode;

    }
};


//* using recursion 

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
    ListNode* removeNodes(ListNode* head) {
        if(head==NULL||head->next==NULL){
            return head;
        }
        ListNode* newNode=removeNodes(head->next);
        if(head->val<newNode->val){
            delete head;
            return newNode;
        }
        head->next=newNode;
        return head;
    }
};


//* using reverse linked list 

