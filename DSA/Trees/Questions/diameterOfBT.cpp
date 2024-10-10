// * Bruteforce
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
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }
        int first=diameterOfBinaryTree(root->left);
        int second=diameterOfBinaryTree(root->right);
        int third=height(root->left)+height(root->right);
        int maxDiameter=max(first,max(second,third));
        return maxDiameter;
    }
};

// * optimal 
class Solution {
public:
    int diameter=0;
    int height(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        // left and right height 
        int left=height(root->left);
        int right=height(root->right);
        // find diameter 
        int currentDiameter=left+right;
        diameter=max(diameter,currentDiameter);
        // return height 
        return (max(left,right)+1);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return diameter;

    }
};