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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int>input;
        while(head!=NULL){
            input.push_back(head->val);
            head=head->next;
        }
        stack<int>st;
        vector<int>ans(input.size());
        for(int i=0;i<input.size();++i){
            while(!st.empty()&&input[st.top()]<input[i]){
                int index=st.top();
                ans[index]=input[i];
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};