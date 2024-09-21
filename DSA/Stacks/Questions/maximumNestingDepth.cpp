class Solution {
public:
    int maxDepth(string s) {
        int maxi=INT_MIN;
        int count=0;
        for(char ch:s){
            if(ch==')'){
                count--;
            }else if(ch=='('){
                count++;
            }
            maxi=max(count,maxi);
        }
        return maxi;
    }
};