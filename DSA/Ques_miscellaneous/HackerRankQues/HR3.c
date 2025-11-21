#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

//    ->>  Given a string, , consisting of alphabets and digits, find the frequency of each digit in the given string.
// Constraints--> 1<=len(num)<=1000
// All the elements of num are made of english alphabets and digits.
// Output Format-Print ten space-separated integers in a single line denoting the frequency of each digit from 0 to 9.


    char s[1000];
    int freq[10] = {0}; 

    scanf("%[^\n]", s); 
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            freq[s[i] - '0']++;
        }
    }

    for (int i = 0; i < 10; i++) {
        printf("%d ", freq[i]);
    }  
    return 0;
}