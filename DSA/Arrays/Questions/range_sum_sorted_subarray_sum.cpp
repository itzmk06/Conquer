// https://leetcode.com/problems/range-sum-of-sorted-subarray-sums/?envType=daily-question&envId=2024-12-28
// * bruteforce
class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        // get the sub array sum 
        vector<int>result;
        for(int i=0;i<n;i++){
            int current_sum=0;
            for(int j=i;j<nums.size();j++){
                current_sum+=nums[j];
            result.push_back(current_sum);
            }
        }
        sort(result.begin(),result.end());
    int sum=0;
    // since sum can be large get modulo at each step of addition to avoid overflow 
    const int MOD = 1e9 + 7;
    for(int i=left-1;i<right;i++){
        sum=(sum+result[i])%MOD;
    }
    return sum;
    }
};
