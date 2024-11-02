class Solution {
public:
    void merge(vector<int>&nums,int beg,int mid,int end){
        // create an empty array 
        vector<int>ans;
        int left=beg;
        int right=mid+1;
        while(left<=mid&&right<=end){
            if(nums[left]<nums[right]){
                ans.push_back(nums[left]);
                left++;
            }else{
                ans.push_back(nums[right]);
                right++;
            }
        }
        // add left array if left 
        while(left<=mid){
            ans.push_back(nums[left]);
            left++;
        }
        // add right array if left 
        while(right<=end){
            ans.push_back(nums[right]);
            right++;
        }
        for(int i=beg;i<=end;i++){
            nums[i]=ans[i-beg];
        }
    }
    void mergeSort(vector<int>&nums,int beg,int end){
        if(beg>=end){
            return ;
        }
        // calculate mid 
        int mid=beg+(end-beg)/2;
        // recursive call for left 
        mergeSort(nums,beg,mid);
        // recursive call for right 
        mergeSort(nums,mid+1,end);
        // merge them 
        merge(nums,beg,mid,end);
    }
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size()-1;
        mergeSort(nums,0,n);
        return nums;
    }
};