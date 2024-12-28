// https://leetcode.com/problems/largest-3-same-digit-number-in-string/
class Solution {
public:
    string largestGoodInteger(string num) {
        string number="";
        for(int i=0;i<num.size()-2;i++){
            if(num[i]==num[i+1]&&num[i+1]==num[i+2]){
                string currentGood=num.substr(i,3);
                if(currentGood>number){
                    number=currentGood;
                }
            }
        }
        return number;
        }
};
