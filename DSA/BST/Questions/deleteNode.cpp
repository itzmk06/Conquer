class Solution {
public:
    int getInorderPredecessor(TreeNode* root){
        while(root->right!=NULL){
            root=root->right;
        }
        return root->val;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        // if tree is empty, nothing to do 
        if(root==NULL){
            return NULL;
        }
        // if current root is target start the process
        if(root->val==key){
            // if left and right both are null 
            if(root->left==NULL&&root->right==NULL){
                return NULL;
            }
            // if left is null 
            if(root->left==NULL&&root->right!=NULL){
                // store the left 
                TreeNode* child=root->right;
                delete root;
                return child;
            }else if(root->left!=NULL&&root->right==NULL){
                TreeNode* child=root->left;
                delete root;
                return child;
            }else{
                // get the inorder predecessor 
                int inorderPredecessor=getInorderPredecessor(root->left);
                // make root to point to that 
                root->val=inorderPredecessor;
                // delete that inorderPredecessor
                root->left=deleteNode(root->left,inorderPredecessor);
            }

        }else if(key>root->val){
            // search in right 
            root->right=deleteNode(root->right,key);
        }else{
            // search in left
            root->left=deleteNode(root->left,key);
        }
        return root;
    }
};