// Print a pattern of numbers from 1 to n as shown below. Each of the numbers is separated by a single space.
// 4 4 4 4 4 4 4 
// 4 3 3 3 3 3 4 
// 4 3 2 2 2 3 4
// 4 3 2 1 2 3 4
// 4 3 2 2 2 3 4
// 4 3 3 3 3 3 4
// 4 4 4 4 4 4 4
// The input will contain a single integer n.
// 2 2 2
// 2 1 2
// 2 2 2
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
int main(){
    int n,a;
    scanf("%d", &n);
      int row = (2*n)-1;
    for(int i=1;i<=row; i++){// (2*n)-1 ->> Length 
        a = n;
        for(int j=1; j<=row; j++){
            printf("%d ",a);
          if(j<i)
            a--;
          if(j>((2*n)-1-i))
            a++;
        }
      printf("\n");
    }
    return 0;
}