//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        int beg = 0;
        int N = arr.size();
        int end = N - 1;
        
        // if array is already sorted then no need to do anything as there is 0 rotations 
        if (arr[beg] <= arr[end]) {
            return 0;
        }

        while (beg <= end) {
            int mid = beg + (end - beg) / 2;

            // Check if mid is the rotation point (smallest element)
            if (arr[mid] < arr[(mid + N - 1) % N] && arr[mid] < arr[(mid + 1) % N]) {
                return mid;
            }
            // Left half is sorted, move right
            else if (arr[mid] >= arr[end]) {
                beg = mid + 1;
            }
            // Right half is unsorted, move left
            else {
                end = mid - 1;
            }
        }

        return 0; // Default case if not found
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input1;
        getline(cin, input1);
        stringstream ss1(input1);
        int number1;
        while (ss1 >> number1) {
            arr.push_back(number1);
        }
        Solution ob;
        int res = ob.findKRotation(arr);
        cout << res << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends