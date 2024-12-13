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


// * using iteration 
//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int target) {
        // intialization 
        int n=arr.size();
        int t[n+1][target+1];
        for(int i=0;i<n+1;i++){
            for(int j=0;j<target+1;j++){
                // false when no elements but sum is not 0 
                if(i==0&&j!=0){
                    t[i][j]=false;
                }
                // sum is 0 
                if(j==0){
                    t[i][j]=true;
                }
            }
        }
        // choice diagram 
        for(int i=1;i<n+1;i++){
            for(int j=1;j<target+1;j++){
                // check whether it's acceptable 
                if(arr[i-1]<=j){
                    // either include it or exclude it 
                    t[i][j]=t[i-1][j-arr[i-1]]||t[i-1][j];
                }else{
                    // exclude it 
                    t[i][j]=t[i-1][j];
                }
            }
        }
        return t[n][target];
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
