class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>st;
        vector<int>result;
        unordered_map<int,int>nge;
        for(int num:nums2){
            while(!st.empty()&&st.top()<num){
                nge[st.top()]=num;
                st.pop();
            }
            st.push(num);
        }
        while(!st.empty()){
            nge[st.top()]=-1;
            st.pop();
        }
        for(int num:nums1){
            result.push_back(nge[num]);
        }
        return result;
    }
};