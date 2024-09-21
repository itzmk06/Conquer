class Solution {
public:
    string clearDigits(string s) {
        stack<int>st;
        for(char ch:s){
            if(!st.empty()){
                if(isdigit(ch)){
                    st.pop();
                }else{
                    st.push(ch);
                }
            }
            if(st.empty()){
                if(!isdigit(ch)){
                    st.push(ch);
                }
            }
        }
        string result="";
        while(!st.empty()){
            result+=st.top();
            st.pop();
        }
        reverse(result.begin(),result.end());
        return result;
    }
};