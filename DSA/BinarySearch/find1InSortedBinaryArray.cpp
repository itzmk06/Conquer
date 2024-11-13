//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int firstIndex(vector<int> &arr) {
        // Your code goes here
        int found=-1;
        int beg=0;
        int end=arr.size()-1;
        while(beg<=end){
            int mid=beg+(end-beg)/2;
            if(arr[mid]==1){
                found=mid;
                end=mid-1;
            }else{
                beg=mid+1;
            }
        }
        return found;
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
        stringstream s1(input);
        int num;
        while (s1 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        cout << ob.firstIndex(arr) << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends