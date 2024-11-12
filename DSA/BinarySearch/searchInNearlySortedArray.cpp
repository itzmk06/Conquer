//{ Driver Code Starts
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int findTarget(vector<int>& arr, int target) {
        // Your code here
        int beg=0;
        int end=arr.size()-1;
        while(beg<=end){
            int mid=beg+(end-beg)/2;
            if(arr[mid]==target){
                return mid;
            }else if(arr[mid-1]==target&&mid-1>=beg){
                return mid-1;
            }else if(arr[mid+1]==target&&mid+1<=end){
                return mid+1;
            }else if(target>arr[mid]){
                beg=mid+2;
            }else{
                end=mid-2;
            }
        }
        return -1;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t-- > 0) {
        string str;
        getline(cin, str);

        stringstream ss(str);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }

        int target;
        cin >> target;
        cin.ignore();
        Solution sln;
        int ans = sln.findTarget(arr, target);
        cout << ans << endl;
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends