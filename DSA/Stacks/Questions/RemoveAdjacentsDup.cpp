class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>st;
        st.push('-');
        int string_length=s.length();
        for(int i=0;i<string_length;i++){
            if(st.top()=='-'||st.top()!=s[i]){
                st.push(s[i]);
            }else{
                st.pop();
            }
        }
        string result="";
        while(st.top()!='-'){
            result.push_back(st.top());
            st.pop();
        }
        reverse(result.begin(),result.end());
        return result;
    }
};