#include<iostream>
using namespace std;
void reverseNUM(int arr[], int n){
     for(int i=0; i<n/2; i++){
        int firstVal= arr[i];
        int secondVal= arr[n-i-1];
        arr[i]= secondVal;
        arr[n-i-1]= firstVal;
     }
}
int main(){
    int N;
    cin>>N;
    int arr[N];
    for(int i=0; i<N;i++){
        cin>>arr[i];
    }
    reverseNUM(arr, N);
    for(int i=0;i<N;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
