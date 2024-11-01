class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // create two maps 
        unordered_map<char,char>map1;
        unordered_map<char,char>map2;
        // loop through strings
        for(int i=0;i<s.length();i++){
            // get chars 
            char ch1=s[i];
            char ch2=t[i];
            // check whether already present 
            if((map1.find(ch1)!=map1.end()&&map1[ch1]!=ch2)||map2.find(ch2)!=map2.end()&&map2[ch2]!=ch1){
                return false;
            }
            // this means it's not mapped so just mapp them 
            map1[ch1]=ch2;
            map2[ch2]=ch1;
        }
        return true;
    }
};