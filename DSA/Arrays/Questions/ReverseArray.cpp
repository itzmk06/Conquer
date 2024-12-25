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

