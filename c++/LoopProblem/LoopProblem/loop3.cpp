#include <iostream>
using namespace std;
int main(){ // To print the reverse of a number
int n;
cout<<"enter a number: ";
cin>>n;
int r=0;
while(n!=0){
    int ld = n%10;
    r*=10;
    r+=ld;
    n/=10; // -> is used to remove the last digit from the integer n.
    // This is done in each iteration of the while loop to eventually break the loop when n becomes 0
}  // 1234/10= 123,  123/10=12,  12/10= 1,  1/10= 0, and then the loop breaks here
cout<<r;
}