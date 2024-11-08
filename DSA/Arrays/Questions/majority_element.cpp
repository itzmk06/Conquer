// * 0(n)-> time and 0(n)-> space
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int num:nums){
            mp[num]++;
        }
        int maxIndex=INT_MIN;
        int maxElement=INT_MIN;
        for(auto i=mp.begin();i!=mp.end();i++){
            if(i->second>maxIndex){
                maxIndex=i->second;
                maxElement=i->first;
            }
        }
        return maxElement;
    }
};