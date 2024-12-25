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

// * using string 
class Solution {
public:
    bool isPalindrome(string s) {
        string new_str="";
        // filter string 
        for(auto i:s){
            if(isalnum(i)){
                new_str+=tolower(i);
            }
        }
        string reversed_str="";
        // reverse string 
        for(int i=new_str.size()-1;i>=0;i--){
            reversed_str+=new_str[i];
        }
        return new_str==reversed_str;

    }
};
