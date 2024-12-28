class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        for(int i=0;i<nums.size();i++){
            int sum=0;
            for(int j=i;j<nums.size();j++){
                sum+=nums[j];
                if(j-i+1>=2&&sum%k==0) return true;    
        }
        }
        return false;
    }
};