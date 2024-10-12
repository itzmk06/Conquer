// * recursive way 
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root==NULL){
            // tree is empty 
            return NULL;
        }
        if(root->val==val){
            return root;
        }else if(val>root->val){
            // search in right 
            return searchBST(root->right,val);
        }else{
            // search in left 
            return searchBST(root->left,val);
        }
        return NULL;
    }
};

// * Iterative way 
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
    TreeNode* searchBST(TreeNode* root, int val) {
        while(root!=NULL){
            if(root->val==val){
                return root;
            }else if(val>root->val){
                // search in right 
                root=root->right;
            }else{
                root=root->left;
            }
        }
        return NULL;
    }
};