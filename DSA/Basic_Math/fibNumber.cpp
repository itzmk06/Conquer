class Solution {
public:
    int fib(int n) {
        int n1=0;
        int n2=1;
        for(int i=1;i<=n;i++){
            int nth=n1+n2;
            n1=n2;
            n2=nth;
        }

        return n1;
    }
};

// * using memoization 
class Solution {
public:
    int fn(int n,vector<int>&dp) {
        if(n<=1){
            return n;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        return dp[n]=fn(n-1,dp)+fn(n-2,dp);
    }
    int fib(int n){
        vector<int>dp(n+1,-1);
        return fn(n,dp);
    }
};
