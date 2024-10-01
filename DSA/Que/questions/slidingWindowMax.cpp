class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        vector<int>ans;

        // traverse first k elements 
        for(int i=0;i<k;i++){
            while(!dq.empty()&&nums[i]>=nums[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        ans.push_back(nums[dq.front()]);

        // handle remaining elements
        for(int i=k;i<nums.size();i++){
            // remove out of window elements 
            while(!dq.empty()&&((i-dq.front())>=k)){
                dq.pop_front();
            }
            
            while(!dq.empty()&&nums[i]>=nums[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);
            ans.push_back(nums[dq.front()]);
        }


        return ans;

    }
};