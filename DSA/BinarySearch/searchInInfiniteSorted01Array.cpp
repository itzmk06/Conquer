/************************************************************

    Use get function that returns the value at index i
    in the infinite sorted binary array.

    get(i)
    {

    }
    

************************************************************/

long long firstOne()
{
    // Write your code here.
    long long beg=0;
    long long end=beg+1;
    while(get(end)!=1){
        beg=end;
        end=end*2;
    }
    long long found=-1;
    while(beg<=end){
        long long mid=beg+(end-beg)/2;
        if(get(mid)==1){
            found=mid;
            end=mid-1;
        }else{
            beg=mid+1;
        }
    }
    return found;
}
