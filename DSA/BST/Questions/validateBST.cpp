class Solution {
public:
    vector<int>ans;
    void inOrderTraversal(TreeNode* root){
        // if root is null 
        if(root==NULL){
            return;
        }
        inOrderTraversal(root->left);
        ans.push_back(root->val);
        inOrderTraversal(root->right);
    }
    bool isValidBST(TreeNode* root) {
        inOrderTraversal(root);
        // check whether array is sorted or not 
        for(int i=0;i<ans.size()-1;i++){
            if(ans[i]>=ans[i+1]){
                return false;
            }
        }
        return true;
    }
};

// * using recursion 
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
    bool solve(TreeNode* root,long long int lowerBound,long long int upperBound){
        // if tree is empty is't valid 
        if(root==NULL){
            return true;
        }
        // check current node is within range 
        if((root->val>lowerBound)&&(root->val<upperBound)){
            bool leftAns=solve(root->left,lowerBound,root->val);
            bool rightAns=solve(root->right,root->val,upperBound);
            return leftAns&&rightAns;
        }else{
            return false;
        }
        return false;
    }
    bool isValidBST(TreeNode* root) {
        long long int lowerBound=-4294967296;
        long long int upperBound=4294967296;
        bool ans=solve(root,lowerBound,upperBound);
        return ans;
    }
};