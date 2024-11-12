// * linear search o(n)

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        for(int i=0;i<letters.size();i++){
            if(letters[i]==target&&(i+1)<letters.size()){
                if(letters[i+1]!=target){
                    return letters[i+1];
                }
            }else if((target-'0')<(letters[i]-'0')){
                return letters[i];
            }
        }
        return letters[0];
    }
};

// * optimal using binary search o(log n)

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int beg=0;
        int end=letters.size()-1;
        char result=letters[0];
        while(beg<=end){
            int mid=beg+(end-beg)/2;
            if(letters[mid]>target){
                result=letters[mid];
                end=mid-1;
            }else{
                beg=mid+1;
            }
        }
        return result;
    }
};