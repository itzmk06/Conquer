class Solution {
public:
    int dp[20001][4];
    int helper(vector<int>&subArray,vector<int>&result,int i,int k,int n,int count){
        if(count==0){
            return 0;
        } 
        if(i>=subArray.size()){
            return INT_MIN;
        }
        if(dp[i][count]!=-1){
            return dp[i][count];
        }

        int take=subArray[i]+helper(subArray,result,i+k,k,n,count-1);
        int dont_take=helper(subArray,result,i+1,k,n,count);
        dp[i][count]=max(take,dont_take);
        return dp[i][count];
    }
    void solve(vector<int>&subArray,vector<int>&result,int i,int k,int n,int count){
        if(count==0){
            return;
        }
        if(i>=subArray.size()){
            return;
        }
        int take_sum=subArray[i]+helper(subArray,result,i+k,k,n,count-1);
        int dont_take_sum=helper(subArray,result,i+1,k,n,count);
        if(take_sum>=dont_take_sum){
            result.push_back(i);
            solve(subArray,result,i+k,k,n,count-1);
        }else{
            solve(subArray,result,i+1,k,n,count);
        }
    }
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        // get sub array 
        vector<int>subArray;
        vector<int>result;
        int i=0,j=0,window_sum=0;
        while(j<nums.size()){
            window_sum+=nums[j];
            if(j-i+1==k){
                subArray.push_back(window_sum);
                window_sum-=nums[i];
                i++;
            }
            j++;
        }
        memset(dp,-1,sizeof(dp));
        int count=3;
        int size=nums.size();
        solve(subArray,result,0,k,size,count);
        return result;
    }
};