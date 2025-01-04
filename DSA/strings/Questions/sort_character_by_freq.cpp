// https://leetcode.com/problems/sort-characters-by-frequency/
class Solution {
public:
    string frequencySort(string s) {
        // get freq 
        unordered_map<char,int>freq;
        // build count 
        for(auto c:s){
            freq[c]++;
        }
        // convert to vector 
        vector<pair<char,int>>freqVector(freq.begin(),freq.end());
        // sort based on comparator 
        sort(freqVector.begin(),freqVector.end(),[](pair<char,int>&a,pair<char,int>&b){
            return a.second>b.second;
        });
        // build result string 
        string result;
        for(auto &p:freqVector){
            result.append(p.second,p.first);
        }
        // return result
        return result;
    }
};
