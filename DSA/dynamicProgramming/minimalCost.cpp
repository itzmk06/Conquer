// * memoization

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int solve(int k,vector<int>&arr,int n,vector<int>&dp){
        // base case
        if(n==0){
            return 0;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        // chioce diagram 
        int left=INT_MAX;
        for(int i=1;i<=k;i++){
            if(n-i>=0){
                int jump=solve(k,arr,n-i,dp)+abs(arr[n]-arr[n-i]);
                left=min(left,jump);}
        }
        return dp[n]=left;
    }
    
    int minimizeCost(int k, vector<int>& arr) {
        int n=arr.size();
        vector<int>dp(n+1,-1);
        return solve(k,arr,n-1,dp);
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minimizeCost(k, arr);
        cout << res << endl;
        cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends
