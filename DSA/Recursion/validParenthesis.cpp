class Solution {
public:
    bool helper(string s,int i,int n){
        // base case 
        if(i>=n/2) return true;
        // solve one case 
        if(s[i]!=s[n-1-i]) return false;
        // give other to recursion
        return helper(s,i+1,n);
    }
    bool isPalindrome(string s) {
        // filter the string with only alnum 
        string new_str="";
        for(char c:s){
            if(isalnum(c)){
                new_str+=tolower(c);
            }
        }
        int n=new_str.size();
        int i=0;
        return helper(new_str,i,n);
    }
};
