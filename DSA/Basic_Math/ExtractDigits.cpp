#include<bits/stdc++.h>
#include<vector>
using namespace std;

int main(){
    vector<int>v;
    int number=12345;
    while(number>0){
        int temp=number%10;
        v.push_back(temp);
        cout<<temp<<" ";
        number=number/10;
        }
        cout<<endl;
        reverse(v.begin(),v.end());
        for(int i:v){
            cout<<i<<" ";
        }
    cout<<endl;
    return 0;
}

