#include<iostream>
using namespace std;

int main(){
    int n; 
    cout<<"Enter the amount: "<<endl; cin>>n;
    int currToffee = 0, rapper = 0, totToffee;
    
    
    while(n > 0){
        currToffee++;
        rapper++;
        if(rapper == 3){
            currToffee+=1;
            rapper = 1;
        }
        n--;
    }

    totToffee = currToffee;
    cout<<"He got: "<<totToffee<<" toffees"<<endl;

}




