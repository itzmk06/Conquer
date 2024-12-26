// https://leetcode.com/problems/find-the-middle-index-in-array/
class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        // get total_sum 
        int total_sum=0;
        for(auto i:nums){
            total_sum+=i;
        }
        // get the running sum 
        int left_sum=0;
        for(int i=0;i<nums.size();i++){
            if(2*left_sum+nums[i]==total_sum){
                return i;
            }
            left_sum+=nums[i];
        }
        return -1;
    }
};
