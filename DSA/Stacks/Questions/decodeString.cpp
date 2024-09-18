class Solution {
public:
    string decodeString(string s) {
        stack<string>st;
        for(auto ch:s){
            string newString="";
            if(ch==']'){
                while(!st.empty()&&st.top()!="["){
                    string temp=st.top();
                    newString+=temp;
                    st.pop();
                }
                if(!st.empty()){
                    st.pop(); 
                }
                string number="";
                if(!st.empty()){
                    while(!st.empty()&&isdigit(st.top()[0])){
                            number+=st.top();
                            st.pop();
                    }

                }
                reverse(number.begin(),number.end());
                int num=stoi(number);
                string decodedString="";
                while((num--)){
                    decodedString+=newString;
                }
                st.push(decodedString);
            }else{
                string temp(1,ch);
                st.push(temp);
            }
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;

    }
};