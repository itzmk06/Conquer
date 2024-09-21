class Solution {
public:
    string removeStars(string s) {
        stack<char>st;
        for(char ch:s){
            if(!st.empty()){
                if(ch=='*'){
                    st.pop();
                }else{
                    st.push(ch);
                }
            }else{
                st.push(ch);
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