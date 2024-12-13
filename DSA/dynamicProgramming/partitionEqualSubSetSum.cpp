class Solution {
public:
    bool subSetSum(vector<int>&nums,int target,int n){
    bool t[n+1][target+1];
        // intialization 
        for(int i=0;i<n+1;i++){
            for(int j=0;j<target+1;j++){
                if(i==0&&target!=0){
                    t[i][j]=false;
                }
                if(j==0){
                    t[i][j]=true;
                }
            }
        }
        // choice diagram 
        for(int i=1;i<n+1;i++){
            for(int j=1;j<target+1;j++){
                // value is valid 
                if(nums[i-1]<=j){
                    // either include it or exclude it 
                    t[i][j]=t[i-1][j-nums[i-1]]||t[i-1][j];
                }else{
                    // exclude it 
                    t[i][j]=t[i-1][j];
                }
            }
        }
        return t[n][target];
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        // get the sum 
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        // we can get equal partion only when even sum is present 
        if(sum%2!=0){
            // this is odd 
            return false;
        }else{
            int target=sum/2;
            return subSetSum(nums,target,n);
        }
    }
};
