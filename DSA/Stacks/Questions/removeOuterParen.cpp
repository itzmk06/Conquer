class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char>st;
        string ans="";
        for(auto c:s){
            if(st.empty()&&c=='('){
                st.push(c);
            }else if(!st.empty()&&c=='('){
                st.push(c);
                ans+=c;
            }else if(!st.empty()&&c==')'){
                st.pop();
                if(!st.empty()){
                    ans+=c;
                }
            }
        }
        return ans;
    }
};