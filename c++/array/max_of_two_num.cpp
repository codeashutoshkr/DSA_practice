#include <iostream>
using namespace std;
int main(){
    int arr[4];
    cout<<"enter the elements of the array: ";
    for(int i=0;i<4;i++){
        cin>>arr[i];
    }
    int mx = arr[0];
    for(int i=0;i<4;i++){
      if(arr[i]>arr[0]) mx = arr[i];
    }
    cout<<mx;
}