#include<iostream>
using namespace std;

int main(){
    // creating one d array 
    int* arr=new int[10];
    for(int i=0;i<10;i++){
        arr[i]=0;
        cout<<arr[i]<<" ";
    }

    //creating 2 d array 
    // define rows
    int **arr1=new int* [5];
    for(int i=0;i<5;i++){
        arr1[i]=new int[5];
    }
    cout<<endl;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            arr1[i][j]=0;
            cout<<arr1[i][j]<<" ";
        }
        cout<<endl;
    }


    delete [] arr;
    for(int i=0;i<5;i++){
        delete [] arr1[i];
    }
    delete [] arr1;
    return 0;
}


