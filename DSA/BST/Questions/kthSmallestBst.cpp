// * Brute force
class Solution {
public:
    vector<int>v;
    void inOrder(TreeNode* root){
        if(root==NULL){
            return;
        }
        inOrder(root->left);
        v.push_back(root->val);
        inOrder(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        inOrder(root);
        return v[k-1];
    }
};

// *optimal 
class Solution {
public:
    int count=1;
    int ans=-1;
    void inOrder(TreeNode* root,int k){
        if(root==NULL){
            return ;
        }
        inOrder(root->left,k);
        if(count==k){
            ans=root->val;
        }
        count++;
        inOrder(root->right,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        inOrder(root,k);
        return ans;
    }
};