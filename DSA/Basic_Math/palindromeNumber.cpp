class Solution {
public:
    int reverse(int x){
         bool positive=x>0?true:false;
     int reversed_number=0;
     x=abs(x);
     while(x>0){
        int last_digit=x%10;
        if(reversed_number>(INT_MAX-last_digit)/10){
            return 0;
        }
        reversed_number=reversed_number*10+last_digit;
        x=x/10;
     }
        if(positive){
            return reversed_number;
        }else{
            return -reversed_number;
        }
    }
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        int reversed_number=reverse(x);
        if(x==reversed_number){
            return true;
        }else{
            return false;
        }
    }
};