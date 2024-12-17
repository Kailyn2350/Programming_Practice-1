#include <stdio.h>

#define EOD -1//End Of Data to identify where is the final data

int Return_max(int arr[]);

int main(void){
    int x[] = {18, 2, 15, 32, 12, 19, 54, 23, 19, EOD};
    
    printf("配列　{%d", x[0]);
    for(int i = 1;  x[i] != EOD; i++){
        printf(", %d", x[i]);
    }
    printf("}\n");
    
    printf("最大値：%d", Return_max(x));
}

int Return_max(int arr[]){
    int Max = arr[0];//save max number
    
    for(int i = 1; arr[i] != EOD; i++){
        if(arr[i] > Max){//identify of Max number
            Max = arr[i];//input max number if arr[i] is max number
        }
    }
    return Max;
}