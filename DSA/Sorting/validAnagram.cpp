// * using sorting (0(nlongn))
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        return s==t;
    }
};

// * using array (0(n))

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>count(26,0);
        for(char c:s){
            count[c-'a']++;
        }
        for(char c:t){
            count[c-'a']--;
        }
        for(int i:count){
            if(i!=0){
                return false;
            }
        }
        return true;

    }
};