class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int maxRight=arr[arr.size()-1];
        int store=arr[arr.size()-1];
        arr[arr.size()-1]=-1;
        for(int i=arr.size()-2;i>=0;i--){
            // store upate 
            store=arr[i];
            // update arr value 
            arr[i]=maxRight;
            // update max right 
            store>maxRight?maxRight=store:maxRight;
        }
        return arr;
    }
};