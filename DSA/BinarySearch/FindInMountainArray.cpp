/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int binarySearch(MountainArray &mountainArr,int beg,int end,int target,bool increasing){
        while(beg<=end){
            int mid=beg+(end-beg)/2;
        if(mountainArr.get(mid)==target){
            return mid;
        }else{
            if(increasing){
                if(target>mountainArr.get(mid)){
                    beg=mid+1;
                }else{
                    end=mid-1;
                }
            }else{
                if(target>mountainArr.get(mid)){
                    end=mid-1;
                }else{
                    beg=mid+1;
                }
            }
        }
        }   
        return -1;

    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int beg=0;
        int end=mountainArr.length()-1;
        // get peak index 
        while(beg<end){
            int mid=beg+(end-beg)/2;
            if(mountainArr.get(mid)<mountainArr.get(mid+1)){
                beg=mid+1;
            }else{
                end=mid;
            }
        }
        // apply binary search 
        int pivot=beg;
        int result1=binarySearch(mountainArr,0,pivot,target,true);
        int result2=binarySearch(mountainArr,pivot+1,mountainArr.length()-1,target,false);
        if(result1!=-1){
            return result1;
        }else{
            return result2;
        }
        return -1;
    }
};
