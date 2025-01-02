#include<iostream>
using namespace std;
int main(){  //To print 'n' number of terms of any series or sequence
    int n;
    cout<<"enter the value of n: ";
    cin>>n;
    int a = 1;
for(int i = 1; i<=n; i++){
    cout<<a<<" ";
    a = a*2;
}
}