#include<iostream>
using namespace std;

int main(){
    int arr[] = {22, 32, 42, 55};
    cout<<"Address at first memory allocation: "<<arr<<endl;
    cout<<"Value at this address: "<<arr[0]<<endl;
    cout<<"Address at first memory allocation: "<<&arr[0]<<endl;
    cout<<"4th "<<*arr<<endl;
    cout<<"5th "<<*arr + 1 <<endl;
    cout<<"6th "<< *(arr + 1)<<endl;
    int i = 3;
    cout<<i[arr]<<endl; // another way of  arr[i]
   
    
}