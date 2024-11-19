/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int beg=1;
        int end=n;
        while(beg<=end){
            int mid=beg+(end-beg)/2;
            int guessed_number=guess(mid);
            if(guessed_number==0){
                return mid;
            }else if(guessed_number>0){
                beg=mid+1;
            }else{
                end=mid-1;
            }
        }
        return -1;
    }
};
