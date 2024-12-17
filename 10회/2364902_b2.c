#include <stdio.h>
#define ARR_LEN 4 //array lenth

int f( int n);
int g( int n );

int main(void){
    int arr[ARR_LEN] = {0, 1, 4, -10};
    
    for(int i = 0; i < ARR_LEN; i++){
        printf("n = %d\n", arr[i]);
        printf("f(n) : %d\n", f(arr[i]));
        printf("g(n) : %d\n", g(arr[i]));
        printf("\n");
    }
}

int f(int n){
    if(n <= 1){//when n <= 1
        return 1;
    }
    else{//when n is not in n <= 1 range
        return (n*g(n-1));
    }
}
int g(int n){
    if(n == 0){//when n is 0
        return 0;
    }
    else{//when n is not 0
        return (n+f(n-1));
    }
}