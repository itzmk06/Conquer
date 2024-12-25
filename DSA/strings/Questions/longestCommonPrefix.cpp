// https://leetcode.com/problems/longest-common-prefix/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // take the first string from array 
        string target=strs[0];
        // iterate each string
        for(int i=1;i<strs.size();i++){
            // now compare each word with target
            int j=0; // compare each char 
            while(j<strs[i].size()&&j<target.size()&&target[j]==strs[i][j]){
                j++;
            }
            target=target.substr(0,j);
            // not j+1 since j+1 now points to invalid index 
            if(target.empty()) return "";
        }
        return target;
    }
};
