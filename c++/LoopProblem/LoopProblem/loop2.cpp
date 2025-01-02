#include <iostream>
using namespace std;
int main(){  //To print sum of the digits of a given number
int n;
cout<<"enter a number: ";
cin>>n;
int sum=0;
while(n!=0){
    int ld = n%10;
    n= n/10; // 0r n/= 10;
    sum+=ld;
}
cout<<sum;
}