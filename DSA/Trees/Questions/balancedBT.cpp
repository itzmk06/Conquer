// * Brute force 
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

// * optimal 

class Solution {
public:
    bool balanced=true;
    int height(TreeNode* root){
        if(root==NULL){
            return true;
        }
        int left=height(root->left);
        int right=height(root->right);
        if(balanced&&(abs(left-right)>1)){
            balanced=false;
        }
        return max(left,right)+1;
    }
    bool isBalanced(TreeNode* root) {
        height(root);
        return balanced;
    }
};