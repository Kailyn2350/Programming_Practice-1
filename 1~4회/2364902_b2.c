#include <stdio.h>

int Euclidean_algorithm(int n1, int n2);

int main(void){
    int num1, num2 = 0;
    
    printf("二つの数字を入力するしてください。\n");
    
    printf("一つ目の数字：");
    scanf("%d", &num1);
    
    printf("二つ目の数字：");
    scanf("%d", &num2);
    
    printf("%d と %d の最大公約数は%dです。", num1, num2, Euclidean_algorithm(num1, num2));
    
}

int Euclidean_algorithm(int n1, int n2){
    if(n1 % n2 == 0){//余りが０のとき
        return n2;
    }
    else{
        return Euclidean_algorithm(n2, n1%n2);
    }
}