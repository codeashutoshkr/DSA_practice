#include<iostream>
#include <vector>
using namespace std;

void insertionSort(int n, vector<int>& arr){
    int key;
    for(int i = 1; i< arr.size(); i++){
        key = arr[i];
        int j = i -1;
        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j-=1;

        }
        arr[j+1] = key;
    }
}
int main(){
    int n;
   cout<<"Enter the size of array: "<<endl;
     cin>>n;
     vector<int> arr(n); cout<<"Enter the elements of the array: "<<endl;
     for(int i=0;i<n;i++){
        cin>>arr[i];
     }
      insertionSort(n,  arr); 
     cout<<"Here is the sorted array using insertion sort algorithm: "<<endl;
     for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
     }
          cout<<endl;
    return 0;
}