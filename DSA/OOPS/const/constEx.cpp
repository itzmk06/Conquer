#include<iostream>
using namespace std;

int main(){
    const int x=5;
    cout<<"The value of const variable is "<<x<<endl;
    // x=6; -> Error can't assign read only variable 
    // cout<<"After update value of const variable is "<<x<<endl;

    int * a=new int;
    *a=3;
    cout<<"Value of a is "<<*a<<endl;
    int b=10;
    delete a;
    a=&b;
    cout<<"The value of a is "<<*a<<endl;

    cout<<"----------------------------"<<endl;

    // const int c=10;
    // c=20; not possible 
    // cout<<"a is "<<c<<endl;


    // const data and non constant pointer 

    // if we create a const pointer variable dynamically 
    // then tried to change the pointer the promise of const 
    // can  be break
    const int * d=new int(10);
    int e=20;
    d=&e;
    cout<<"value of d is "<<*d<<endl;
    // this works 
    // when we make the variable as const 
    // and we have created the variable dynamically 
    // then the data of it can't be changed but it's 
    // pointer can be reassigned 

    // const pointer but non constant data

    int *const f=new int(10);
    cout<<"value of f is "<<*f<<endl;
    *f=100;
    cout<<"value of f now is "<<*f<<endl;
    //here the data is non-constant but
    int g=10;
    // f=&g; -> pointer can't be changed 
    // cout<<"now value of f is "<<*f<<endl;
    // so here becomes the pointer const 
    
    // now if we want const data as well const pointer 
    int const *const h=new int(100);
    cout<<"the value of h is "<<*h<<endl;
    // *h=0; won't work 
    int i=10;
    //h=&i; won't work 
    
    // * These are the three ways of working with const 







    return 0;
}