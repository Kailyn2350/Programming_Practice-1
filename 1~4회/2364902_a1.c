#include <stdio.h>

int gcd(int arr[]);
int Euclidean_algorithm(int n1, int n2);

int main(void){
    int input[100];
    
    printf("3個以上目自然数を入力してください。\n");
    printf("10以下の入力で終了。0以下が入力する直前までの全ての自然数の最大公約数を表示します。\n");
    for(int i = 0; i < 100; i++){
        printf("%d 個めの自然数：", i+1);
        scanf("%d", &input[i]);
        
        if(input[i] <= 0){
            break;
        }
    }
    
    printf("0以下が入力する直前までの全ての自然数の最大公約数は%d", gcd(input));
    
    return 0;
}

int gcd(int arr[]){
    int result = 0;
    for(int i = 0; arr[i] > 0; i++){
        result = Euclidean_algorithm(result, arr[i]);
    }
    return result;
}

int Euclidean_algorithm(int n1, int n2){
    if(n1 % n2 == 0){//余りが０のとき
        return n2;
    }
    else{
        return Euclidean_algorithm(n2, n1%n2);
    }
}

