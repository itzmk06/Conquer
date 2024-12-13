// * using memozization

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // memozization 
    int t[1006][1006];
    int knap(vector<int>&wt,vector<int>&val,int w,int n){
        // base case 
        if(n==0||w==0){
            return 0;
        }
        // memozization 
        if(t[n][w]!=-1){
            return t[n][w];
        }
        // choice 
        if(wt[n-1]<=w){
            return t[n][w]=max(val[n-1]+knap(wt,val,w-wt[n-1],n-1),knap(wt,val,w,n-1));
        }else if(wt[n-1]>w){
            return t[n][w]=knap(wt,val,w,n-1);
        }
        return -1;
    }
  
    // Function to return max value that can be put in knapsack of capacity.
    int knapSack(int capacity, vector<int> &val, vector<int> &wt) {
        // code here
        memset(t,-1,sizeof(t));
        int n=val.size();
        return knap(wt,val,capacity,n);
    }
};

//{ Driver Code Starts.

int main() {
    // Taking total test cases
    int testCases;
    cin >> testCases;
    cin.ignore();
    while (testCases--) {
        // Reading number of items and capacity
        int numberOfItems, capacity;
        vector<int> weights, values;
        string input;
        int number;

        // Read capacity and number of items
        getline(cin, input);
        stringstream ss(input);
        ss >> capacity;      // The first number is the capacity
        ss >> numberOfItems; // The second number is the number of items

        // Read values
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            values.push_back(number);
        }

        // Read weights
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            weights.push_back(number);
        }

        Solution solution;
        cout << solution.knapSack(capacity, values, weights) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends


// * using table form

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return max value that can be put in knapsack of capacity.
    int knapSack(int capacity, vector<int> &val, vector<int> &wt) {
        // create a table 
        int n=val.size();
        int t[n+1][capacity+1];
        // intialize 0th and oth row and col 
        for(int i=0;i<n+1;i++){
            for(int j=0;j<capacity+1;j++){
                if(i==0||j==0){
                    t[i][j]=0;
                }
            }
        }
        // fill out other values  
        for(int i=1;i<n+1;i++){
            for(int j=1;j<capacity+1;j++){
                if(wt[i-1]<=j){
                    t[i][j]=max((val[i-1]+t[i-1][j-wt[i-1]]),(t[i-1][j]));
                }else if(wt[i-1]>j){
                    t[i][j]=t[i-1][j];
                }
            }
        }
        return t[n][capacity];
    }
};

//{ Driver Code Starts.

int main() {
    // Taking total test cases
    int testCases;
    cin >> testCases;
    cin.ignore();
    while (testCases--) {
        // Reading number of items and capacity
        int numberOfItems, capacity;
        vector<int> weights, values;
        string input;
        int number;

        // Read capacity and number of items
        getline(cin, input);
        stringstream ss(input);
        ss >> capacity;      // The first number is the capacity
        ss >> numberOfItems; // The second number is the number of items

        // Read values
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            values.push_back(number);
        }

        // Read weights
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            weights.push_back(number);
        }

        Solution solution;
        cout << solution.knapSack(capacity, values, weights) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends