// optimal approach -> o(log n)

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int beg=0;
        int end=arr.size()-1;
        while(beg<end){
            int mid=beg+(end-beg)/2;
            if(arr[mid]<arr[mid+1]){
                beg=mid+1;
            }else{
                end=mid;
            }
        }
        return beg;
    }
};


// bruteforce approach -> 0(n)

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int i=0;
        while(i<arr.size()-1&&arr[i]<arr[i+1]){
            i++;
        }
        return i;
    }
};
