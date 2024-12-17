#include <stdio.h>

int main(void){
    int a = 3, b = 7;
    printf("a = %d b = %d\n", a, b);
    b = b-a;// a : a, b : b-a;
    a = a+b;// a : a + b - a = b, b : b-a;
    b = a-b;// a : a + b - a = b, b : b - b + a = a
    printf("a = %d b = %d\n",a, b);
    
    return 0;
}