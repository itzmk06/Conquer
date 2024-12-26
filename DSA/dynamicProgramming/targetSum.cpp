// https://leetcode.com/problems/target-sum/?envType=daily-question&envId=2024-12-26
// * Brute force 
class Solution {
public:
    int solve(vector<int>&nums,int target,long long current_sum,int i){
        if(i==nums.size()){
            if(target==current_sum){
                return 1;
            }
            return 0;
        }

        // add 
        int plus=solve(nums,target,current_sum+nums[i],i+1);
        // minus
        int minus=solve(nums,target,current_sum-nums[i],i+1);
        return plus+minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        long long current_sum=0;
        return solve(nums,target,current_sum,0);
    }
};
