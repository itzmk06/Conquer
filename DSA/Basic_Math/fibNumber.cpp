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

// * with tabulation 
class Solution {
public:
    int fn(int n,vector<int>&dp) {
        // base case => intialization 
        dp[0]=0;
        if(n>0){
            dp[1]=1;
        }
        // choice diagram filling 
        for(int i=2;i<n+1;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
    int fib(int n){
        vector<int>dp(n+1,-1);
        return fn(n,dp);
    }
};

// * space optimization 
class Solution {
public:
    int fn(int n,vector<int>&dp) {
        if(n<=1){
            return n;
        }
        int prev2=0;
        int prev=1;
        for(int i=2;i<n+1;i++){
            int curr=prev+prev2;
            prev2=prev;
            prev=curr;
        }
        return prev;
    }
    int fib(int n){
        vector<int>dp(n+1,-1);
        return fn(n,dp);
    }
};
