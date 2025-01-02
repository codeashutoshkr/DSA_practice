#include<iostream>
using namespace std;
int main(){
// { To print number pattern like this- 12345
//                                      12345
//                                      12345
int n;
cout<<"enter a number: ";
cin>>n;                 
for(int i = 1; i<=n;i++){
    for(int j=1; j<=n;j++){
        cout<<j;
    }
    cout<<endl;
}
}