class Solution {
public:
    vector<int>ans;
    void inOrder(TreeNode* root){
        if(root==NULL){
            return;
        }
        inOrder(root->left);
        ans.push_back(root->val);
        inOrder(root->right);
    }
    bool findTarget(TreeNode* root, int k) {
        inOrder(root);
        int beg=0;
        int end=ans.size()-1;
        while(beg<end){
            int sum=ans[beg]+ans[end];
            if(sum==k){
                return true;
            }else if(k>sum){
                beg++;
            }else{
                end--;
            }
        }
        return false;
    }
};