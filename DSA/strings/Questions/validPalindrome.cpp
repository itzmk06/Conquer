// * using stack 
class Solution {
public:
    bool isPalindrome(string s) {
        stack<char>st;
        for(char ch:s){
            if(isalpha(ch)){
                st.push(tolower(ch));
            }
            else if(isdigit(ch)){
                st.push(ch);
            }
        }
        string reverseString="";
        while(!st.empty()){
            reverseString+=st.top();
            st.pop();
        }
        string copy=reverseString;
        reverse(reverseString.begin(),reverseString.end());
        return copy==reverseString;
        
    }
};

