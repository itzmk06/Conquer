// https://www.naukri.com/code360/problems/frog-jump_3621012?leftPanelTabValue=SUBMISSION
#include <bits/stdc++.h> 

int solve(int n,vector<int>&heights,vector<int>&dp){
    if(dp[n]!=-1){
        return dp[n];
    }
    // if one step move 
    int oneStep=solve(n-1,  heights,dp)+abs(heights[n]-heights[n-1]);
    // if two step move
    int twoStep=INT_MAX;
    if(n>1){
        twoStep=solve(n-2,  heights,dp)+abs(heights[n]-heights[n-2]);
    }
    dp[n]=min(oneStep,twoStep);
    return dp[n];

}

int frogJump(int n, vector<int> &heights)
{
    vector<int>dp(n+1,-1);
    dp[0]=0;
    return solve(n-1,heights,dp);
}
