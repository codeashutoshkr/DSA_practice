#include <iostream>
#include<vector>
using namespace std;

void selectionSort(vector<int>& arr, int n ){
    for(int i =0; i<n; i++){
        int minIndex = i ;
        for(int j = i+1; j <n; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j ;
            }
        }
        swap(arr[minIndex], arr[i]);
    }

}

int main(){
    int n ; cout<<"enter the size of array: "<<endl;
      cin>>n;
    vector<int> arr(n);
    cout<<"Enter the elements of the array: "<<endl;
    for(int i =0; i<n; i++){
        cin>>arr[i];
    }
     selectionSort(arr, n);
     for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
     }
     cout<<endl;
     return 0;
}