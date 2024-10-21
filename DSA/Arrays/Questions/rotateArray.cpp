// *Brute force 
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int>ans;
            int K=k%nums.size();
            int need=nums.size()-K;
            for(int i=need;i<nums.size();i++){
                ans.push_back(nums[i]);
                nums[i]=-1;
            }
            for(int i=0;i<need;i++){
                ans.push_back(nums[i]);
            }
            for(int i=0;i<ans.size();i++){
                nums[i]=ans[i];
            }
    }
};

// * optimal 
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // get the size 
        int n=nums.size();
        // reverse whole array 
        reverse(nums.begin(),nums.end());
        // get the actual value of k within range
        int K=k%n;
        // reverse k elements of array 
        auto value=nums.begin()+K;
        reverse(nums.begin(),value);
        // reverse k+1 elements till end 
        reverse(value,nums.end());

    }
};
