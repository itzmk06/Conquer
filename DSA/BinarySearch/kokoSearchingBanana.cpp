class Solution {
public:
    bool compute(vector<int>piles,int h,int mid){
        int hours=0;
        for(int n:piles){
             hours+=n/mid;
            // if banana is not completed he takes one hour again to complete
            if(n%mid!=0){
                hours++;
            }
        }
        // if we complete all bananas with mid banana in each hour then proceed which is within that h
        if(hours<=h){
            return true;
        }else {
            return false;
        }
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int beg=1;
        int end=*max_element(piles.begin(),piles.end());
        while(beg<end){
            int mid=beg+(end-beg)/2; // this is number of banana's it can eat in an hour
            if(compute(piles,h,mid)){
                // mid number of bananas can be eaten in an hour so that he completes all bananas, but we find min
                end=mid;
            }else{
                // he can't complete so take further 
                beg=mid+1;
            }
            // now beg points to min return it 
        }
            return beg;
    }
};