class Solution {
public:
    int compute(vector<int>&nums,int mid,int threshold){
        long long sum=0;
        for(int num:nums){
            sum+=(num+mid-1)/mid;
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int beg=1;
        int end=*max_element(nums.begin(),nums.end());
        long long result=-1;
        while(beg<=end){
            long long mid=beg+(end-beg)/2;
            // compute for current divisor 
            long long computeResult=compute(nums,mid,threshold);
            if(computeResult<=threshold){
                // store result
                result=mid;
                // search smaller result 
                end=mid-1;
            }else{
                beg=mid+1;
            }
        }
        return result;
    }
};