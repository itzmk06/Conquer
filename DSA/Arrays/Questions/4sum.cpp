class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>result;
        // sort vector 
        sort(nums.begin(),nums.end());
        // traverse whole vector 
        int n=nums.size();
        for(int i=0;i<n;i++){
            // if any duplicates skip  it 
            if(i>0&&nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<n;j++){
                // if duplicates skip it
                if(j!=i+1&&nums[j]==nums[j-1]) continue;
                int k=j+1;
                int l=n-1;
                while(k<l){
                    long long sum=nums[i]+nums[j];
                    sum+=nums[k];
                    sum+=nums[l];
                    if(sum==target){
                        vector<int>ans;
                        ans.push_back(nums[i]);
                        ans.push_back(nums[j]);
                        ans.push_back(nums[k]);
                        ans.push_back(nums[l]);
                        result.push_back(ans);
                        k++;
                        l--;
                        // skip duplicates 
                        while(k<l&&nums[k]==nums[k-1]) k++;
                        while(k<l&&nums[l]==nums[l+1]) l--;
                    }else if(sum>target){
                        l--;
                    }else{
                        k++;
                    }

                }
            }

        }
        return result;
    }
};
