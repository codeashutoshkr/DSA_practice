#include <iostream>
using namespace std;
//   Find Square Root of an Integer[both int & floating part] using Binary Search without using in-built functions


long long int binarySearch(int n){
    int s = 0, e = n -1 ;
    long long int mid = s + (e - s)/2 ;
    long long int ans = -1;
    
    while(s <= e){
         long long int sq = mid * mid ;
    if(sq == n){
        return mid ;
    }
    else if(sq < n){
        ans = mid ;
        s = mid + 1;
    }
    else{
        e = mid - 1;
    }
    mid = s + (e - s)/2;
}

return ans ;
}
 long long int squareRoot(int x){
    return binarySearch(x);  // for only integer part use this function
}
  double morePrecision(int n, int precision, int intPrt){ // for both integer and floating part use this function
          double factor = 1;
          double sqRoot = intPrt ;
          for(int i =0; i< precision; i++){
            factor = factor/10;
          
            for(double j = sqRoot; j*j < n; j = j + factor ){
                sqRoot = j ;
            }
          }
       return sqRoot;
  }

int main(){
    int n; cout<<"Enter a number to find it's square root "<<endl;
    cin>>n;
    int intPrt = squareRoot(n);
    double preciseSqRoot = morePrecision(n, 3, intPrt); // here 3 shows that we want precision for 3 decimal places
    cout<<preciseSqRoot<<endl; 
}
