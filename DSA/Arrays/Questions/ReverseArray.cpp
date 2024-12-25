//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void reverseArray(vector<int> &arr) {
        int beg=0;
        int end=arr.size()-1;
        while(beg<end){
            int temp=arr[beg];
            arr[beg]=arr[end];
            arr[end]=temp;
            beg++;
            end--;
        }
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

        Solution ob;
        ob.reverseArray(arr);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends
=======
// * using recursion
// https://www.geeksforgeeks.org/problems/reverse-an-array/0
class Solution {
  public:
    void doReverse(vector<int>&arr,int i,int n){
        if(i>=n/2) return;
        swap(arr[i],arr[n-i-1]);
        doReverse(arr,i+1,n);
    }
    void reverseArray(vector<int> &arr) {
        // code here
        int n=arr.size();
        int i=0;
        doReverse(arr,i,n);
    }
};

>>>>>>> 11ae5d3747190e6f357823c79608a24c8d0c4ea8
