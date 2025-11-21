// To create an integer array,arr of size n, int *arr = (int*)malloc(n * sizeof(int)), 
// where arr points to the base address of the array.
//  When you have finished with the array, use free(arr) to deallocate the memory.
//  In this challenge, create an array of size  dynamically, and read the values from stdin.
//   Iterate the array calculating the sum of all elements. Print the sum and free the memory where the array is stored.

// While it is true that you can sum the elements as they are read, without first storing them to an array, 
// but you will not get the experience working with an array. Efficiency will be required later.
#include<stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
int *ptr;
int n;
int sum = 0;
scanf("%d", &n);
ptr = (int*)malloc(n*sizeof(int));
if(ptr==NULL){
    exit(EXIT_FAILURE);
}
for(int i=0;i<n;i++){
    scanf("%d",ptr+i);
    sum += *(ptr+i);
}
    printf("%d", sum);
    free(ptr);
    return 0;
}