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

    void solve(TreeNode* root,int targetSum,vector<vector<int>>&ans,vector<int>temp,int sum){
        // if no nodes are present 
        if(root==NULL){
            return;
        }
        // store details 
        sum+=root->val;
        temp.push_back(root->val);
        // check whether it's a leaf node 
        if(root->left==NULL&&root->right==NULL){
        // if reached leaf node check whether it's sum=target sum 
            if(sum==targetSum){
                ans.push_back(temp);
            }else{
                return;
            }
        }
        // we solved one state now give recursion to handle left substree and right subtree
        solve(root->left,targetSum,ans,temp,sum);
        solve(root->right,targetSum,ans,temp,sum);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>temp;
        int sum=0;
        solve(root,targetSum,ans,temp,sum);
        return ans;      
    }
};