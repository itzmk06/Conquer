class Solution {
public:
    string makeGood(string s) {
        stack<char>st;
        st.push(s[0]);
        for(int i=1;i<s.length();i++){
            if(!st.empty()){
                if(s[i]+32==st.top()||s[i]-32==st.top()){
                    st.pop();
                    continue;
                }
            }
            st.push(s[i]);
        }
        string newString="";
        while(!st.empty()){
            newString+=st.top();
            st.pop();
        }

        reverse(newString.begin(),newString.end());
        return newString;

    }
};