// https://leetcode.com/problems/number-of-ways-to-split-array/description/
class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        // get total sum 
        long long total_sum=0;
        for(auto i:nums){
            total_sum+=i;
        }
        // get left sum 
        int count=0;
        long long left_sum=0;
        for(int i=0;i<nums.size()-1;i++){
            left_sum+=nums[i];
            // get right sum 
            long long right_sum=total_sum-left_sum;
            if(left_sum>=right_sum){
                count++;
            }
        }
        return count;
    }
};
