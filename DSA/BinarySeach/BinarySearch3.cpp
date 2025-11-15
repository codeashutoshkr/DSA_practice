/*
 To find pivot element in a sorted and rotated array
*/
 #include <iostream>
 using namespace std;
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

  int main(){
    int n; cin>>n;
    int arr[n];
    for(int i =0; i<n; i++){
        cin>>arr[i];
    }
    int pivot = getPivot(n, arr);
    cout<<pivot<<endl;
    
  }