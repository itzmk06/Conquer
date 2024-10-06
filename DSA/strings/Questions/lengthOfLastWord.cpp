class Solution {
public:
    int lengthOfLastWord(string s) {
        int count=0;
        // remove spaces from left which are trailing 
        int j=s.length()-1;
        while(s[j]==' '){
                j--;
        }
        // get the lenght untill you found a space 
        for(int i=j;i>=0;i--){
            if(s[i]==' '){
                return count;
            }
            count++;
        }
        return count;

    }
};