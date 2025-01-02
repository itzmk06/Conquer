// * bruteforce

class Solution {
public:
    bool rotateString(string s, string goal) {
        // if size of s and goal ! then false 
        if(s.size()!=goal.size()) return false;
        // s+s includes all combinations of s 
        string new_s=s+s;
        // check whether goal is present in new_s
        return new_s.find(goal)!=string::npos;
    }
};

// * optimal 
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
