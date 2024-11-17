//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    int findMaximum(vector<int> &arr) {
        // code here
        int beg=0;
        int end=arr.size()-1;
        while(beg<end){
            int mid=beg+(end-beg)/2;
            if(arr[mid]>arr[mid+1]&&arr[mid]>arr[mid-1]){
                return arr[mid];
            }else if(arr[mid]>arr[mid-1]){
                beg=mid+1;
            }else{
                end=mid-1;
            }
        }
        return arr[beg];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        int value;

        // Read the entire line of integers
        string line;
        // cin.ignore(); // Ignore the newline after the test case input
        getline(cin, line);
        stringstream ss(line);

        // Parse integers and add them to the vector
        while (ss >> value) {
            arr.push_back(value);
        }

        Solution ob;
        auto ans = ob.findMaximum(arr);
        cout << ans << "\n";
        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends