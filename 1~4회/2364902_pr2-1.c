#include <stdio.h>

int main(void){
    int a = 3, b = 7, temp;//臨時の変数tempを宣言
    printf("a = %d b = %d\n", a, b);
    temp = a;//入れ替える作業。
    a = b;
    b = temp;
    
    printf("a = %d b = %d\n",a, b);
    
    return 0;
}