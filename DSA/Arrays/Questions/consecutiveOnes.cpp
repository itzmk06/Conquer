class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        if(nums.size()==1&&nums[0]==1){
             return 1;
        }else if(nums.size()==1&&nums[0]==0){
            return 0;
        }else if(nums.size()==2&&nums[0]==0&&nums[1]==0){
            return 0;
        }
        int maxi=INT_MIN;
        int count=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]&&nums[i]==1&&nums[i+1]==1){
                count++;
            }else{
                count=0;
            }
            if(count>maxi){
                maxi=count;
            }
        }
        return maxi+1;
    }
};