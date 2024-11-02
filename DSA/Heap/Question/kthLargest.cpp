class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>q;
        // traverse whole array 
        for(int num:nums){
            // push element 
            q.push(num);
            // if size is more than k remove it 
            if(q.size()>k){
                q.pop();
            }
        }
        // return top element 
        return q.top();
    }
};