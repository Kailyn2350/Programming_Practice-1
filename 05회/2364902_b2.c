#include <stdio.h>

void count_number_print(int arr[]);//count number and print

int main(void){
    int x[100];
    printf("0～9 の任意の整数を入力してください ( 入力終了は EOF 制御文字 ) :\n");
    for(int i = 0;; i++){
        x[i] = getchar();
        if(x[i] == EOF){//End Of File (if you input ctrl + D)
            break;
        }
    }

    count_number_print(x);
    
    return 0;
}

void count_number_print(int arr[]){
    int c[10] = {0, };
    for(int i = 0; arr[i] != EOF; i++){
        for(int j = 48; j < 57; j++){// ASCII of 0 ~ 9 is 48 ~ 56
            if(arr[i] == j){
                c[j-48]++;//initializing of j range 48 ~ 56 into 0 ~ 9
            }
        }
    }
    
    for(int i = 0; i < 10; i++){
        printf("%dの個数は %d\n", i, c[i]);
    }
}