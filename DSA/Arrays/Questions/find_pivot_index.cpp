// https://leetcode.com/problems/find-pivot-index/
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total_sum=0;
        // get total sum 
        for(auto i:nums){
            total_sum+=i;
        }
        // 2* left_sum + nums[i] = total_sum 
        // get running sum 
        int left_sum=0;
        for(int i=0;i<nums.size();i++){
            if(2*left_sum+nums[i]==total_sum){
                return i;
            }
            // add to running sum
            left_sum+=nums[i];
        }
        return -1;
    }
};
