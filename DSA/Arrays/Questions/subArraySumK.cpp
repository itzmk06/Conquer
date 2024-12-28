// bruteforce 
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count=0;
        for(int i=0;i<nums.size();i++){
            for(int j=i;j<nums.size();j++){
                // calculate sum 
                int sum=0;
                for(int k=i;k<=j;k++){
                    sum+=nums[k];
                }
                // check whether the sum = k 
                if(sum==k) count++;
            }
        }
        return count;
    }
};
