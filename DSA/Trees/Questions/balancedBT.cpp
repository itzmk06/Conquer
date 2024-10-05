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
    int height(TreeNode* root){
        if(root==nullptr){
            return 0;
        }
        int left=height(root->left);
        int right=height(root->right);
        return max(left,right)+1;
    }
    bool isBalanced(TreeNode* root) {
        if(root==nullptr){
            return true;
        }
        int currentNodeDiff=abs(height(root->left)-height(root->right));
        bool currentNode=false;
        if(currentNodeDiff<=1){
            currentNode=true;
        }
        bool leftSubTreeAns=isBalanced(root->left);
        bool rightSubTreeAns=isBalanced(root->right);
        if(leftSubTreeAns&&rightSubTreeAns&&currentNode){
            return true;
        }else{
            return false;
        }

        
    }
};