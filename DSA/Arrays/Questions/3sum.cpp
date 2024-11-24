class Solution {
public:
    void twoSum(vector<int>&nums,int target,int beg,int end,vector<vector<int>>&result){
        while(beg<end){
            int sum=nums[beg]+nums[end];
            if(sum>target){
                // sum is large -> decrease it move left 
                end--;
            }else if(sum<target){
                // sum is small -> increase it move right 
                beg++;
            }else{
                // it means sum = target but handle duplicates 
                while(beg<end&&nums[beg]==nums[beg+1]) beg++;
                while(beg<end&&nums[end]==nums[end-1]) end--;
                // since sum = target push to result 
                result.push_back({-target,nums[beg],nums[end]});
                // move the pointers 
                beg++;
                end--;
            }
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        int size=nums.size()-1;
        vector<vector<int>>result;
        // sort array 
        sort(nums.begin(),nums.end());
        // traverse whole array 
        for(int i=0;i<size;i++){
            // skip duplicates 
            if(i>0&&nums[i]==nums[i-1]){
                // if duplicates are present continue 
                continue;
            }
            // get the target 
            int target=-nums[i];
            // apply two sum
            twoSum(nums,target,i+1,size,result);
        }
        // return array 
        return result;
    }
};
