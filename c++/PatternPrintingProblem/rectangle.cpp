#include <iostream>
using namespace std;
int main(){ // to print a solid rectangle of side m*n;
int m, n;
cout<<"enter the length of  the rectangle: ";
cin>>m;
cout<<"enter the breadth of the rectangle: ";
cin>>n;
for(int i=1;i<=m;i++){
    for(int j=1;j<=n;j++){
    cout<<"*";
}
cout<<endl;
}
}