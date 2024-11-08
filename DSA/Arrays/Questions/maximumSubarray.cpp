class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // set sum to 0 
        int sum=0;
        // set maxi as first element of array 
        int maxi=nums[0];
        // traverse entire array 
        for(auto num:nums){
            // calculate sum
            sum+=num;
            // update maxi 
            maxi=max(sum,maxi);
            // if sum is negative update sum to 0 
            if(sum<0){
                sum=0;
            }
        }
        return maxi;
    }
};