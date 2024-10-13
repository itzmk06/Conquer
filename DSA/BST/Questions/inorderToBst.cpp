class Solution {
public:
    TreeNode* solve(vector<int>&nums,int beg,int end){
        // base case 
        if(beg>end){
            return NULL;
        }
        // calculate mid
        int mid=beg+(end-beg)/2;
        // create a node for mid
        TreeNode* newNode=new TreeNode(nums[mid]);
        // put beg to mid-1 to left of new node 
        newNode->left=solve(nums,beg,mid-1);
        newNode->right=solve(nums,mid+1,end);
        return newNode;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int beg=0;
        int end=nums.size()-1;
        TreeNode* ans=solve(nums,beg,end);
        return ans;
    }
};