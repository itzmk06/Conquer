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
    bool solve(TreeNode* root,int targetSum,int sum){
        // no nodes are present
        if(root==NULL){
            return false;
        }
        // calculate sum
        sum+=root->val;
        // compare when at leaf node 
        if(root->left==NULL&&root->right==NULL){
            if(targetSum==sum){
                return true;
            }else{
                return false;
            }
        }
        // move to left
        int leftAns=solve(root->left,targetSum,sum);
        // move to right
        int rightAns=solve(root->right,targetSum,sum);

        // if you found ans at left or right return it 
        return leftAns||rightAns;


    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum=0;
        bool ans=solve(root,targetSum,sum);
        return ans;
    }
};