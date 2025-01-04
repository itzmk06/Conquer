// https://leetcode.com/problems/roman-to-integer/
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int>mp;
        // store constants 
        mp['I']=1;
        mp['V']=5;
        mp['X']=10;
        mp['L']=50;
        mp['C']=100;
        mp['D']=500;
        mp['M']=1000;
        int number=0;
        // traverse string 
        for(int i=0;i<s.size();i++){
            if(i+1<s.size()&&mp[s[i]]<mp[s[i+1]]){
                // if i-> smaller , subtract with next and skip i+1
                number+=(mp[s[i+1]]-mp[s[i]]);
                i+=1;
            }else{
                // current is higher so just add that 
                number+=mp[s[i]];
            }
        }
        return number;
        
    }
};
