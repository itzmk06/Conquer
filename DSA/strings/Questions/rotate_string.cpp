// https://leetcode.com/problems/rotate-string/
class Solution {
public:
    bool rotateString(string s, string goal) {
        // if lenghts are not equal 
        if(s.size()!=goal.size()) return false;
        // rotate 0th and last index 
        for(int i=0;i<s.size();i++){
            int last=s.size()-1;
            s=s.substr(1)+s[0];
            if(s==goal) return true;    
        }
        return false;
    }
};
