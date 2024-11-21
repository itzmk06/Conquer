//* this is using linear search 

//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:

    bool canIPlaceCows(vector<int>&stalls,int distance,int k){
        // we'll place first cow at zeroth index
        int count=1;
        int lastPosition=stalls[0];
        for(int i=1;i<stalls.size();i++){
            if(stalls[i]-lastPosition>=distance){
                // this means we can store the cow here 
                // update cow position 
                lastPosition=stalls[i];
                count++;
            }
            // if we placed all cows return true 
            if(count>=k){
                return true;
            }
        }
        // we're not able to place all cows return false 
        return false;
    }

    int aggressiveCows(vector<int> &stalls, int k) {
        // Write your code here
        // sort the vector 
        sort(stalls.begin(),stalls.end());
        int minDistance=1;
        int maxDistance=stalls[stalls.size()-1]-stalls[0];
        int ans=-1;
        // loop from min distance to max distance 
        for(int i=minDistance;i<=maxDistance;i++){
            if(canIPlaceCows(stalls,i,k)){
                ans=i;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int k;
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string in;
        getline(cin, in);
        stringstream sss(in);
        int num;
        while (sss >> num) {
            k = num;
        }
        Solution ob;
        int ans = ob.aggressiveCows(arr, k);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
