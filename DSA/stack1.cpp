#include<iostream>
#include<stack>
using namespace std;

int main(){

    // create stack
    stack<int> S;
    
    //push operations
    S.push(2);
    S.push(3);
    
    //pop operation
    S.pop();
    cout<<"THe top element in the stack: "<<S.top()<<endl;

    if(S.empty()){
        cout<<"Stack is empty"<<endl;
    }
    else{
        cout<<"Stack is not empty"<<endl;
    }
    
    
}