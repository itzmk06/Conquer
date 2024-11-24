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

//* optimal 
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int closest_sum = 6868656;
        // sort karlo
        sort(nums.begin(), nums.end());
        // two sum daldo
        // traverse whole array
        for (int k = 0; k <= nums.size() - 3; k++) {
            int i = k + 1;
            int j = nums.size() - 1;
            while (i < j) {
                // get sum
                int sum = nums[i] + nums[j] + nums[k];
                if (abs(target - sum) < abs(target - closest_sum)) {
                    closest_sum = sum;
                }
                if(sum<target){
                    i++;
                }else{
                    j--;
                }

            }
        }
        return closest_sum;
    }
};
