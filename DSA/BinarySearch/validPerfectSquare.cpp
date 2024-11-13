    class Solution {
    public:
        bool isPerfectSquare(int num) {
            if(num<=1){
                return true;
            }
            int beg=1;
            int end=num;
            while(beg<=end){
                long long mid=beg+(end-beg)/2;
                if(mid*mid==num){
                    return true;
                }else if(mid*mid<num){
                    beg=mid+1;
                }else{
                    end=mid-1;
                }
            }
            return false;
        }
    };