class Solution {
public:
    int firstUniqChar(string s) {
        int arr[26]={0};
        int count=0;
        for(char ch:s){
            arr[ch-'a']++;
        }
        int n=sizeof(arr)/sizeof(int);
        for(int i=0;i<s.length();i++){
            if(arr[s[i]-'a']==1){
                return i;
            }
        }
         return -1;

    }
};