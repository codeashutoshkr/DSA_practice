#include <iostream>
using namespace std;
int binarySearch(int arr[], int size, int key){
    int start = 0; int end = size - 1; 
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
            
            int even[6] = {2, 4, 6, 8, 12, 18};
            int odd[5] = {3, 5, 7, 9, 13};
              int evenIndex = binarySearch(even, 6, 20);
              cout<<"Index of 20 is "<<evenIndex<<endl;
              int oddIndex = binarySearch(odd, 5, 9);
              cout<<"Index of 9 is "<<oddIndex<<endl;
            
        }

