// https://www.geeksforgeeks.org/problems/sum-of-first-n-terms5843/0
//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int solve(int n,long long int sum){
        if(n<1){
            return sum;
        }
        solve(n-1,sum+(n*n*n));
    }
    int sumOfSeries(int n) {
        // code here
        long long int sum=0;
        return solve(n,sum);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.sumOfSeries(N) << "\n";

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends