class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i=0,j=0;
        stack<int>st;
        int len=pushed.size();
        while(i<len){
            st.push(pushed[i]);
            while(j<len&&!st.empty()&&popped[j]==st.top()){
                st.pop();
                j++;
            }
            i++;
        }
        return st.empty();


    }
};