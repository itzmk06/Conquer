//* Bruteforce -> 0(n^3)

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int minDiff=INT_MAX;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                for(int k=j+1;k<nums.size();k++){
                    int sum=nums[i]+nums[j]+nums[k];
                    int diff=abs(sum-target);
                    if(diff<=minDiff){
                        minDiff=diff;
                        ans=sum;
                    }
                }
            }
        }
        return ans;
    }
};
