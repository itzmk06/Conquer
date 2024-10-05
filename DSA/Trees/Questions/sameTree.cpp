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
    bool helper(TreeNode* p,TreeNode* q){
        if(p==NULL&&q==NULL){
            return true;
        }else if(p!=NULL&&q==NULL){
            return false;
        }else if(p==NULL&&q!=NULL){
            return false;
        }
        if(p->val!=q->val){
            return false;
        }
        bool left=helper(p->left,q->left);
        bool right=helper(p->right,q->right);
        return left&&right;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool ans=helper(p,q);
        return ans;
    }
};