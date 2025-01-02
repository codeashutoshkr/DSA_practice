#include <iostream>
using namespace std ;
//   To Search an Element in a Sorted & Rotated array using Binary Search

 int getPivot(int n, int arr[]){
    int s = 0 , e = n - 1 ;
    int mid = s + (e - s)/2 ;
    while(s < e){
        if(arr[mid] >= arr[0]){
            s = mid + 1;
        }
        else {
            e = mid ;
        }
        mid = s + (e - s)/2;
    }
    return s ;
 }
 int binarySearch(int arr[], int s, int e, int key){
    int start = s; int end = e; 
    int mid = start + (end - start)/2; // we can also use (start + end)/2 but for larger value like 2^30 -1 
                                      //it will fail because int can't store
        while(start <= end){
            if(arr[mid] == key){
                return mid;
            }
            // otherwise go to right part
            if(key > arr[mid]){
                start = mid + 1;
            }
            else {
                end = mid -1;
            }
            mid = start + (end - start)/2;
        }                              
        return -1;
}
 
 int main(){
    int n = 5;
    int arr[5] = {3, 5, 9, 1, 2}; int k = 9 ; // k should be an element of the array 
     int pivot = getPivot(n, arr);
    if(k >= arr[pivot] && k <= arr[n - 1]){
        cout<<binarySearch(arr, pivot, n-1, k)<<endl;
    }
    else {
        cout<<binarySearch(arr, 0, pivot-1, k)<<endl;
    }
 }