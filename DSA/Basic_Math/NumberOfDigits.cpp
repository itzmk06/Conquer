#include<bits/stdc++.h>
using namespace std;

// * Brute force 
// int main(){
//     int count=0;
//     int n=12345;
//     int N=n;
//     while(n>0){
//         int temp=n%10;
//         count++;
//         n=n/10;
//     }
//     cout<<"Number of digit's in "<<N<<" is "<<count<<endl;

//     return 0;
// }

//*Optimal 
int main(){
    int count=0;
    int n=12345;
    int result=log10(n)+1;
    cout<<"Number of digits in "<<n<<" is "<<result<<endl;
}