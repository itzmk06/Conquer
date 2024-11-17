class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int beg=1;
        int i=0;
        int n=arr.size();
        while(k>0){
            // check whether num is in arr 
            if(i<arr.size()&&arr[i]==beg){
                // if present skip this
                i++;
            }else{
                // that element is not present decrement k 
                k--;
            }
            // k=0? then this is our target element 
            if(k==0) return beg;
            beg++;
        }
        return beg;
    }
};