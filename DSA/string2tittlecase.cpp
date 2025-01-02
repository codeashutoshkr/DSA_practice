#include<iostream>
using namespace std;
int main(){  //Given a string S consisting of only lowercase and uppercase English letters and spaces, 
//your task is to convert it into title case. In title case, the first letter of each word is capitalized 
//while the rest are in lowercase, except for words that are entirely in uppercase (considered as acronyms),
 //which should remain unchanged.
    int t;
    cin>>t;
    cin.ignore(); //clear buffer after reading t
    while(t--){
        string s;
        cin>>s;
        int n= s.size();
        for(int i=0;i<n;i++){
            if(i==0|| s[i-1]==' '){
               s[i]= toupper(s[i]);
            }
            else if(isupper(s[i])&& (islower(s[i-1]))|| islower(s[i+1])){
                s[i]= tolower(s[i]);
            }
        }
        cout<<s<<endl;
    }
    return 0;
}