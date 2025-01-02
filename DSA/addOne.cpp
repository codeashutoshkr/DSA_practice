#include <bits/stdc++.h>
using namespace std;
#define ll long long
/*You are given a large number N. You need to print the number 𝑁+1.
Note: The number is very large and it will not fit in standard integer data type.
You have to take the input as String and then manipulate the digits to convert it to 𝑁+1.
*/
string solve(string s)
{
    int l=s.size()-1;
    while(l!=-1)
    {  
        
    /* Taking out each char from the right side of the string
    and converting it to integer using following concept:
    
    Minus char 0 returns original digit and changes its datatype
    to integer number
    */
    int n=s[l]-'0';
    
    // Checking if adding 1 to a digit is strictly greater than 9
    // then we replace that char or digit with '0'
    
    if(n+1>9)
    {
        if(l==0)
        {   /* this condition comes into play when a given number 
                starts with digit 9 .
                Let us take number 9 or 99 or 999 or 9011
                in these number we have to append "10" at starting and leaving 
                0-indexed place and all others changes according to following conditions  given down.
                To append "10" at starting I have substring method which returns all string leaving 0-indexed character or digit. */
             
            s="10" + s.substr(1,s.size());
            break; // it helps to break the loop and  returns our final string 
        }
        s[l]='0';
        l--;
    }
    
    // if on adding 1 to a digit is strictly less than 10
    else
    {
        s[l]=(n+1)+'0'; // adding '0' to number converts its datatype to char
        break;
    }
    
    }
    return s; // finally converted string is returned
}

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        cout<<solve(s)<<endl;
    }
}