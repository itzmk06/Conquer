class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        // create a vector to store ans 
        vector<int>ans(nums.size());
        int beg=0;
        int end=nums.size()-1;
        int index=nums.size()-1;
        while(beg<=end){
            int begAns=nums[beg]*nums[beg];
            int endAns=nums[end]*nums[end];
            // insert larget one to ans
            if(begAns>endAns){
                ans[index]=begAns;
                beg++;
            }else{
                ans[index]=endAns;
                end--;
            }
            // decrement index
            index--;
        }
        return ans;

    }
};