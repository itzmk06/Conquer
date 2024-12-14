//https://leetcode.com/problems/climbing-stairs/
class Solution {
public:
    int fn(int n,vector<int>&dp) {
        for(int i=2;i<n+1;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
    int climbStairs(int n){
        vector<int>dp(n+1,-1);
        // intialization 
        dp[0]=1;
        dp[1]=1;
        return fn(n,dp);
    }
};
