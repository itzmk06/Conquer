class Solution {
public:
    int reverse(int x) {
        int revNumber=0;
        bool positive=x>=0?true:false;
        if(x<0){
            x=abs(x);
        }
        while(x>0){
            int last_digit=x%10;
            if(revNumber>(INT_MAX-last_digit)/10){
                return 0;
            }
            revNumber=last_digit+revNumber*10;
            x=x/10;
        }
        if(positive){
            return revNumber;
        }else{
            return -revNumber;
        }

    }
};