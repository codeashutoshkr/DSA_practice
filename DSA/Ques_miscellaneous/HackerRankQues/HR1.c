// Given a string,s, consisting of alphabets and digits, find the frequency of each digit in the given string.
// constraints- 1<= len(num)<=1000, all the elements of num are made up of digits and alphabets.
// Output format- Print ten space-separated integers in a single line denoting the frequency of each digit from 0 to 9.
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int main(){
    char s[1000];
    int freq[10]= {0};
    printf("enter a string consists of alphabets and digits\n");
    scanf("%[^\n]", s);
    for(int i =0;i<strlen(s); i++){
        if(s[i]>='0' && s[i]<='9'){
            freq[s[i] -'0']++;
        }
    }
    for(int i=0;i<10; i++){
        printf("%d ", freq[i]);
    }
return 0;
}
