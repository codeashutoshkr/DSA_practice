 #include<stdio.h>
 
 
   int main(){
  char A[] = {'a', 'b', 'c', 'd', 'e', 'f'};
  char *p = A;
  p++;
  while(*p != 'e'){
    printf("%c", *p++);
  }
  
  return 0;
}