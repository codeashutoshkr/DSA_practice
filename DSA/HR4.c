// --> You will be given an integer n, and a threshold,k.For each number i form 1 through n
// find the maximum value of the logical and, or and xor when compared against
//  all integers through n that are grater than i.
//  consider a value only if the comparison returns a result less than k
//  Print the results of the and, or and exclusive or comparisons on separate lines
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//Complete the following function.


void calculate_the_maximum(int n, int k) {
   int max_and=0,max_or=0,max_xor=0;
  for(int i=1;i<=n;i++)
  {
      for(int j=i+1;j<=n;j++)
      {
          if(((i&j)>max_and) && ((i&j)< k))
          {
              max_and=(i&j);
          }
          if(((i|j)>max_or) && ((i|j)< k))
          {
              max_or=(i|j);
          }
          if(((i^j)>max_xor) && ((i^j)< k))
          {
              max_xor=(i^j);
          }
        //(((i&j)<max_and) && ((i&j)> k))? :(max_and=(i&j));
        //(((i|j)<max_or) && ((i|j)> k))? :(max_or=(i|j));
        //(((i^j)<max_xor) && ((i^j)> k))? :(max_xor=(i^j));
          
      }
  }
  printf("%d\n%d\n%d",max_and,max_or,max_xor);
}

int main() {
    int n, k;
  
    scanf("%d %d", &n, &k);
    calculate_the_maximum(n, k);
 
    return 0;
}
