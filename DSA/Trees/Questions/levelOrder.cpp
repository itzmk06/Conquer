/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*>q;
        vector<vector<int>>ans;
        if(root==NULL){
            return ans;
        }
        // push root element 
        q.push(root);
        while(!q.empty()){
            // get the size 
            int size=q.size();
            // store all the elements of particular level 
            vector<int>temp={};
            for(int i=0;i<size;++i){
                TreeNode* node=q.front();
                q.pop();
                temp.push_back(node->val);
            // push the left and right nodes to queue 
            if(node->left!=NULL){
                q.push(node->left);
            }
            if(node->right!=NULL){
                q.push(node->right);
            }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};