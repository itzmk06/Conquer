// https://leetcode.com/problems/left-and-right-sum-differences/description/
class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int>left_sum;
        vector<int>right_sum;
        left_sum.push_back(0);
        // get left sum and right sum 
        int beg=0;
        int left=0;
        int right=0;
        // get left sum array 
        for(int i=0;i<nums.size()-1;i++){
            left+=nums[i];
            left_sum.push_back(left);
        }
        // get right sum array 
        right_sum.push_back(0);
        for(int i=nums.size()-1;i>=1;i--){
            right+=nums[i];
            right_sum.push_back(right);
        }
        reverse(right_sum.begin(),right_sum.end());
        // calculate the result and store in new array 
        vector<int>result;
        for(int i=0;i<left_sum.size();i++){
            result.push_back(abs(left_sum[i]-right_sum[i]));
        }
        return result;
    }
};
