// * Recursive approach 

class Solution {
public:
    bool isValid(string s) {
        if(s.size()==0){
            return true;
        }

        int index=s.find("abc");
        
        if(index!=string::npos){
            string left=s.substr(0,index);
            string right=s.substr(index+3,s.size());
            return isValid(left+right);
        }

        return false;
    }
};

// * optimal approach 

class Solution {
public:
    bool isValid(string s) {
        if(s[0]!='a'){
            return false;
        }
        stack<char>st;
        for(char c:s){
            if(c=='a'){
                st.push(c);
            }else if(c=='b'&&!st.empty()){
                if(st.top()=='a'){
                    st.push(c);
                }else{
                    return false;
                }
            }else{
                if(!st.empty()){
                    if(st.top()=='b'){
                        st.pop();
                    }else{
                        return false;
                    }
                    if(st.top()=='a'){
                        st.pop();
                    }else{
                        return false;
                    }
                }

            }

        }
        return st.empty();

    }
};