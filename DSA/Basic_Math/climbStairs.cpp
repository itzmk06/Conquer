// * using memoization 
class Solution {
public:
    int fn(int n,vector<int>&dp) {
        // memo
        if(dp[n]!=-1){
            return dp[n];
        }
        // choice diagram 
        dp[n]=fn(n-1,dp)+fn(n-2,dp);
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
