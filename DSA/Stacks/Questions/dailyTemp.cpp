class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        stack<int>st;
        vector<int>ans(t.size());
        for(int i=t.size()-1;i>=0;i--){
            while(!st.empty()&&t[i]>=t[st.top()]){
                st.pop();
            }
            if(!st.empty()){
                ans[i]=st.top()-i;
                st.push(i);
            }else{

            ans[i]=0;
            st.push(i);
            }
        }
        return ans;

    }
};