#include<iostream>   // find the first and the last occurrance of the elements of an array
using namespace std;

  int firstOccurance( int arr[], int n, int key){
      int st = 0, end = n - 1, index = -1;
      int mid = st + (end - st)/2 ;
      while(st <= end){
        if(arr[mid] ==  key){
            index = mid;
            end = mid -1;
        }
        else if(arr[mid] > key){  // right me jao
                end = mid - 1;
        }
        else if(arr[mid] < key){
            st = mid + 1;
        }
        mid = st + (end - st)/2;
      }
          
           return index;
  }
   int lastOccurance( int arr[], int n, int key){
      int st = 0, end = n - 1, index = -1;
      int mid = st + (end - st)/2 ;
      while(st <= end){
        if(arr[mid] ==  key){
            index = mid;   
            st = mid + 1;   // -> To check whether there is other key in the last or not
        }
        else if(arr[mid] > key){  // -> left me jao
               end = mid - 1;
        }
        else if(arr[mid] < key){  // -> right me jao
           st = mid + 1;
        }
        mid = st + (end - st)/2;
      }
          
           return index;
  }


int main(){

     int even[6] = {2, 4, 4, 6, 8, 10};
     cout<<"First occurance of 4 is "<<firstOccurance(even, 6, 4)<<endl;
     cout<<"Last occurance of 8 is "<<lastOccurance(even, 6, 8)<<endl;

       return 0;
}