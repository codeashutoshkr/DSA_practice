#include <iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter the value of n: ";
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){ //Logic:we have to increase j and i simultaneously
                              //such that when i= 2 then j should be 2
         cout<<j<<" ";    // we can use any symbol other than a number
        }
        cout<<endl;
    }
}