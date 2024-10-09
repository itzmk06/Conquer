// * Brute force using vectors 
class Solution {
public:
    vector<int>root1Leafs;
    vector<int>root2Leafs;
    void preOrder(TreeNode* root,vector<int>&ans){
        if(root==NULL){
            return;
        }
        if(root->left==NULL&&root->right==NULL){
            ans.push_back(root->val);
        }
        preOrder(root->left,ans);
        preOrder(root->right,ans);
    }
    bool check(vector<int>leafs1,vector<int>leafs2){
        if(leafs1.size()!=leafs2.size()){
            return false;
        }else{
            int i=0;
            int j=0;
            while(i<leafs1.size()&&j<leafs2.size()){
                if(leafs1[i]!=leafs2[j]){
                    return false;
                }
                    i++;
                    j++;
            }
        }
        return true;
        

    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        preOrder(root1,root1Leafs);
        preOrder(root2,root2Leafs);
        return check(root1Leafs,root2Leafs);

    }
};

// * optimal using strings 


class Solution {
public:
    void preOrder(TreeNode* root,string &result){
        if(root==NULL){
            return;
        }
        if(root->left==NULL&&root->right==NULL){
            result+=to_string(root->val)+"_";
        }
        preOrder(root->left,result);
        preOrder(root->right,result);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
    string leafs1="";
    string leafs2="";
    preOrder(root1,leafs1);
    preOrder(root2,leafs2);
    return leafs1==leafs2;
    }
};