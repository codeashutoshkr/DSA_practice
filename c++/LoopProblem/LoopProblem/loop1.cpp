#include<iostream>
using namespace std;
int main(){  //A program to count digits of a number
    int n;
    cout<<"enter a number: ";
    cin>>n;
    int count=0;
    while(n!=0){
        n=n/10;
        count++;
    }
    cout<<count;
}