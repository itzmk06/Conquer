class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;
        for(char ch:num){
            if(st.empty()){
                st.push(ch);
            }else if(!st.empty()){
                while(!st.empty()&&ch<st.top()&&k>0){
                    st.pop();
                    k--;
                }
                st.push(ch);
            }
        }
        while(!st.empty()&&k>0){
            st.pop();
            k--;
        }

        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        int i=0;
        while(i<ans.length()&&ans[i]=='0'){
            i++;
        }
        ans=ans.substr(i);
        return ans.length()==0?"0":ans;

    }
};