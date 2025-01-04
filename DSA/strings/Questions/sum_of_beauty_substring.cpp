// bruteforce
class Solution {
public:
    int beautySum(string s) {
        int total=0;
        // get substrings 
        for(int i=0;i<s.size();i++){
            // get freq 
            unordered_map<char,int>mp;
            for(int j=i;j<s.size();j++){
                mp[s[j]]++;
                // get min max 
                int maxi=INT_MIN;
                int mini=INT_MAX;
                for(auto &temp:mp){
                    maxi=max(maxi,temp.second);
                    mini=min(mini,temp.second);
                }
                // get beauty
                int sum=maxi-mini;
                total+=sum;
            }
        }
        return total;
    }
};

// better
class Solution {
public:
    int beautySum(string s) {
        int total=0;
        // generate substrings
        for(int i=0;i<s.size();i++){
            int freq[26]={0};
            for(int j=i;j<s.size();j++){
                int maxi=INT_MIN;
                int mini=INT_MAX;
                // store freq 
                freq[s[j]-'a']++;
                // get min max
                for(int i=0;i<26;i++){
                    if(freq[i]>0){
                        maxi=max(maxi,freq[i]);
                        mini=min(mini,freq[i]);
                    }
                }
                total+=maxi-mini;
            }
        }
        return total;
    }
};
