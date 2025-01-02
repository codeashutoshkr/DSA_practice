#include <iostream>
using namespace std;
void swap(int *a, int *b){
     int temp = *a;
      *a = *b;
      *b= temp; 
}
int main(){
    int x,y;
    cout<<"enter the value of x: ";
    cin>>x;
    cout<<"enter the value of y: ";
    cin>>y;
    cout<<"Before swapping: "<<x<<"  "<<y<<endl;
    swap(&x,&y);
    cout<<"After swapping: "<<x<<"  "<<y<<endl;
}