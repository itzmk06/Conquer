class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int>ans;
        int beg=0;
        int end=numbers.size()-1;
        while(beg<end){
            int sum=numbers[beg]+numbers[end];
            if(sum==target){
                ans.push_back(beg+1);
                ans.push_back(end+1);
                return ans;
            }
            else if(target>sum){
                beg++;
            }else{
                end--;
            }
        }
        return ans;
    }
};