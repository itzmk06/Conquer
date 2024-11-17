int binarySearch(vector<int>&A,int beg,int end,int B){
    while(beg<=end){
        int mid=beg+(end-beg)/2;
        if(A[mid]==B){
            return mid;
        }else if(B>A[mid]){
            beg=mid+1;
        }else{
            end=mid-1;
        }
    }
    return -1;
}

int Solution::solve(vector<int> &A, int B) {
    int beg=0;
    int end=A.size()-1;
    int peakIndex=-1;
    while(beg<end){
        int mid=beg+(end-beg)/2;
        if(A[mid]>A[mid-1]&&A[mid]>A[mid+1]){
            peakIndex=mid;
            break;
        }else if(A[mid]>A[mid-1]){
            beg=mid+1;
        }else{
            end=mid-1;
        }
    }
    int result1=binarySearch(A,0, peakIndex,B);
    int result2=binarySearch(A,peakIndex,A.size()-1,B);
    if(result1!=-1){
        return result1;
    }else{
        return result2;
    }
}
