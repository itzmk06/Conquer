#include<iostream>
using namespace std;
void printNumbersTillN(int n){
    if(n==0){
        return;
    }
    printNumbersTillN(n-1); // go to the end -> reach 1 
    cout<<n<<endl; // start printing 
}
int main(){
    int n;
    cout<<"Enter value of n:";
    cin>>n;
    printNumbersTillN(n);
}