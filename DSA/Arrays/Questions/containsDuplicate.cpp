// * Using hash map 

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++){
            if(m.find(nums[i])!=m.end()){
                m[nums[i]]++;
            }else{
                m[nums[i]]=1;
            }
        }
        for(auto i=m.begin();i!=m.end();i++){
            if((i->second)>1){
                return true;
            }
        }
        return false;
    }
};

// *-------------------------------------------------------------------


// * Better -> using sorting 
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]){
                return true;
            }
        }
        return false;
    }
};