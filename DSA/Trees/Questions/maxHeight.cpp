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

//  *using recursion 

class Solution {
public:
    int maxDepth(TreeNode* root) {
        // if no nodes are present 
        if(root==NULL){
            return 0;
        }
        // get hieght of left 
        int leftHieght=maxDepth(root->left);
        int rightHieght=maxDepth(root->right);
        int hieght=max(leftHieght,rightHieght)+1;
        return hieght;
    }
};

//* using level order traversal 

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
    int maxDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        queue<TreeNode*>q;
        // push first node into queue 
        q.push(root);
        int count=0;
        while(!q.empty()){
            //get size of queue 
            int size=q.size();
            for(int i=0;i<size;i++){
            TreeNode* frontEle=q.front();
            q.pop();
            // once you remove all elements of size 
            // add left and right 
            if(frontEle->left!=NULL){
                q.push(frontEle->left);
            }
            if(frontEle->right!=NULL){
                q.push(frontEle->right);
            }
            
            }
            count++;
        }
        return count;
    }
};