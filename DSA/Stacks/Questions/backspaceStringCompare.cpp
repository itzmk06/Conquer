// * my bruteforce
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char>st1;
        stack<char>st2;
        for(char c:s){
            if(c!='#'){
                st1.push(c);
            }else{
                if(!st1.empty())
                    st1.pop();
            }
        }
        for(char c:t){
            if(c!='#'){
                st2.push(c);
            }else{
                if(!st2.empty())
                    st2.pop();
            }
        }
        string s1="";
        while(!st1.empty()){
            s1+=st1.top();
            st1.pop();
        }
        string s2="";
        while(!st2.empty()){
           s2+=st2.top();
        st2.pop();
        }
        return s1==s2?true:false;


    }
};