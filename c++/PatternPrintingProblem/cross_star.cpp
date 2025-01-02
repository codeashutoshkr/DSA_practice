#include <iostream>
using namespace std;
#include <math.h>
int main(){                 //To print cross star
   int n;                                               
   int a=0;                                           
   cout<<"enter the value of n ";                       
   cin>>n;
   for(int i=1; i<=n;i++){
    for(int j=1;j<=n;j++){
     if((i+j)==n+1||i==j){
      cout<<"*";
     }
     else{
      cout<<" ";
     }
   }
    cout<<endl;
   }                     
}
