// * using memozization 
//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int t[206][600];
    bool checkSubsetSum(vector<int>&arr,int target,int n){
        // base case 
        // no elements in array 
        if(n==0&&target!=0){
            return t[n][target]=false;
        }
        if(target==0){
            return t[n][target]= true;
        }
        if(t[n][target]!=-1){
            return t[n][target];
        }
        // choice diagram 
        if(arr[n-1]<=target){
            return t[n][target]= checkSubsetSum(arr,target-arr[n-1],n-1)||checkSubsetSum(arr,target,n-1);
        }else{
            return t[n][target]=checkSubsetSum(arr,target,n-1);
        }
        
    }
    bool isSubsetSum(vector<int>& arr, int target) {
        int n=arr.size();
        memset(t,-1,sizeof(t));    
        return checkSubsetSum(arr,target,n);
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();

        Solution ob;
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends