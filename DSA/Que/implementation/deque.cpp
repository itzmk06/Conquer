#include<iostream>
#include<deque>
using namespace std;

int main(){
    deque<int>d;
    d.push_front(10);
    d.push_front(20);
    d.push_front(30);
    d.push_front(40);
    d.push_front(50);
    d.push_back(1);
    d.push_back(2);
    d.push_back(3);
    d.push_back(4);
    d.push_back(5);
    d.push_back(6);
    d.pop_front();
    d.pop_front();
    d.pop_front();
    d.pop_back();
    d.pop_back();
    d.pop_back();
    cout<<d.front()<<endl;
    cout<<d.back()<<endl;
    cout<<d.size()<<endl;


}