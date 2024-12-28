// https://leetcode.com/problems/largest-odd-number-in-string/
class Solution {
public:
    string largestOddNumber(string num) {
        // traverse from end 
        for(int i=num.size()-1;i>=0;i--){
            if((num[i]-'0')%2!=0){
                // number is odd 
                return num.substr(0,i+1);
            }
        }
        return "";
    }
};
