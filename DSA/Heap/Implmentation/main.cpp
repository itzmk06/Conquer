#include<iostream>
using namespace std;

class Heap{
    public:
        int size=0;
        int arr[100];
        Heap(){
            arr[0]=-1;
            this->size=0;
        }
        void insert(int value){
            // increase size by 1 
            this->size=this->size+1;
            // add the element to this index 
            int index=this->size;
            this->arr[index]=value;
            // make the element to present at correct position 
            // we took index >1 because if it's =1 then then parent will be 0 which we dont want 
            while(index>1){
                // get the parent index
                int parentIndex=index/2;
                // get the parent element 
                int parentElement=this->arr[parentIndex];
                // check whether parent < current 
                if(parentElement<arr[index]){
                    // swap the elements 
                    swap(arr[index],arr[parentIndex]);
                    // update the current index value 
                    index=parentIndex;
                }else{
                    // no need to do anything 
                    break;
                }
            }
        }
        int deletion(){
            // here  root node will be deleted
            int index=1;
            int ans=arr[index];
            // replace the root node with last value 
            arr[index]=arr[size];
            // reduce size of array 
            size--;
            // now make new root node to correct pos 
            int largest=index;
            while(index<size){
                            // compare with left and right 
            int left=2*index;
            int right=2*index+1;
            if(left<size&&arr[largest]<arr[left]){
                largest=left;
            }
            if(right<size&&arr[largest]<arr[right]){
                largest=right;
            }
            if(index==largest){
                break;
            }else{
                swap(arr[index],arr[largest]);
                // update index 
                index=largest;
            }
            }
            // return root value 
            return ans;
        }

        // * creating heapify method 
        void heapify(int arr[],int size, int index){
            int left=2*index;
            int right=2*index+1;
            int largest=index;
            // compare with left and right 
            if((left<=size)&&(arr[largest]<arr[left])){
                largest=left;
            }
            if((right<=size)&&(arr[largest]<arr[right])){
                largest=right;
            }
            if(largest!=index){
                // means the current index is not at correct pos 
                swap(arr[index],arr[largest]);
                    // update index of that node 
                    index=largest;
                    heapify(arr,size,index);
            }
        }

        void buildHeap(int arr[],int size){
            this->size=size-1;
            for(int i=size/2;i>0;i--){
                heapify(arr,size,i);
            }
        }

        void heapSort(int arr[],int n){
            // swap first node with last 
            while(n!=1){
                swap(arr[1],arr[n--]);
                heapify(arr,n,1);
            }
        }

};

int main(){
    // Heap h;
    // for(int i=1;i<6;i++){
    //     int temp=0;
    //     cin>>temp;
    //     h.insert(temp);
    // }
    // cout<<"\nPrinting the elements:";
    // for(int i=1;i<h.size;i++){
    //     cout<<h.arr[i]<<" ";
    // }
    // cout<<"\nElement an element:";
    // int new_value;
    // cin>>new_value;
    // h.insert(new_value);

    // cout<<"\nPrinting the elements after insertion:";
    // for(int i=1;i<=h.size;i++){
    //     cout<<h.arr[i]<<" ";
    // }
    // cout<<"\nPerforming deletion.....\n";
    // h.deletion();
    // for(int i=1;i<=h.size;i++){
    //     cout<<h.arr[i]<<" ";
    // }
    Heap h;
    int array[]={ -1, 50, -30, 100, -1, 500, 300, 100, 20, -50, 0, 60, -10, 100, 200, -1000, 1000, 5, 0 };
    int size=18;
    h.buildHeap(array,size);
    cout<<endl;
    cout<<"Printing heap elements:";
    for(int i=1;i<size;i++){
        cout<<array[i]<<" ";
    }
    h.heapSort(array,18);
    cout<<endl;
        cout<<"Printing heap elements:";
    for(int i=1;i<size;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
    return 0;
}



// *_______________________________________________________________________________________________
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void heapify(vector<int>& arr, int size, int index) {
        int left = 2 * index + 1;     // Adjusted for 0-based indexing
        int right = 2 * index + 2;
        int largest = index;

        // Compare with left and right children
        if (left < size && arr[largest] < arr[left]) {
            largest = left;
        }
        if (right < size && arr[largest] < arr[right]) {
            largest = right;
        }

        // Swap and continue heapifying if needed
        if (largest != index) {
            swap(arr[index], arr[largest]);
            heapify(arr, size, largest);
        }
    }

    void heapSort(vector<int>& arr, int n) {
        // Build heap (rearrange array)
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(arr, n, i);
        }

        // One by one extract an element from the heap
        for (int i = n - 1; i > 0; i--) {
            // Move current root to end
            swap(arr[0], arr[i]);
            // Call max heapify on the reduced heap
            heapify(arr, i, 0);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        heapSort(nums, nums.size());
        return nums;
    }
};
