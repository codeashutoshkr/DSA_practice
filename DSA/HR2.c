// Task- Given a positive integer denoting n, do the following:
// If 1 <= n <= 9, then print the lowercase English word corresponding to the number (e.g., one for 1, two for 2, etc.).
// If n > 9, print Greater than 9.
// Constraints- 1 <= n <= 10^9


// #include <math.h>

// #include <stdio.h>






// int main()
// {
//     int n;
//    scanf("%d", &n);
//    if(n==1){
//        printf("one");
//    }
//    else if(n==2){
//        printf("two");
//    }
//    else if(n==3){
//        printf("three");
//    }
//    else if(n==4){
//        printf("four");
//    }
//    else if(n==5){
//        printf("five");
//    }
//    else if(n==6){
//        printf("six");
//    }
//    else if(n==7){
//        printf("seven");
//    }
//    else if(n==8){
//        printf("eight");
//    }
//    else if(n==9){
//    printf("nine");
// }
// else {
//     printf("Grater than 9");
// }
// }
//.................................................................................................
//..................................||OR||.................................................................
//.................................................................................................
#include <stdio.h>

static const char *numbers[] = { "one", "two", "three", "four", "five",
                                "six", "seven", "eight", "nine" };
int main() {
    int n = 0;
    if (scanf("%d", &n) < 1) {
        return 1;
    }
    
    if (n >= 1 && n <= 9) {
        printf("%s", numbers[n-1]);
    } else {
        printf("Greater than 9");
    }
    
    return 0;
}