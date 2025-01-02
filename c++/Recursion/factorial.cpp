#include <iostream>
using namespace std;

int factorial(int n){
    // base case
    if(n == 0){
        return 1;
    }
    int num1 = factorial(n-1);   
    int num2 = n * num1;   // instead of these steps we can directly write 
    return num2;          //  return n * factorial(n-1)
}

int main(){
    int n;
    cout<<"Enter a number: "; cin>>n;
    int fact = factorial(n);
    cout<<"Factorial of "<<n<<" is "<<fact<<endl;

}