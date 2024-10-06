class Solution {
public:
    void reverseString(vector<char>& s) {
        int first=0;
        int last=s.size()-1;
        for(int i=0;i<(s.size())/2;i++){
            int temp=s[first];
            s[first]=s[last];
            s[last]=temp;
            first++;
            last--;
        }
    }
};