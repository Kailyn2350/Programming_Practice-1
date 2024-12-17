#include <stdio.h>

int Binomial_Coefficient(int n, int k);

int main(void){
    int k = 0;
    int n = 0;
    int result = 0;
    
    printf("n, kを入力してください（だたし、0 < k < n)\n");
    
    printf("n = ");
    scanf("%d", &n);
    printf("k = ");
    scanf("%d", &k);
    if(k <= 0 || k >= n){//when k is not value in 0 < k < n range
        printf("0 < k < n ではありません");//print error massage
    }
    else{
        printf("%d", Binomial_Coefficient(n, k));//print return value
    }
}

int Binomial_Coefficient(int n, int k){
    if(k == 0){
        return 1;
    }
    else if(k == n){
        return 1;
    }
    else if(0 < k && k < n){//range of  0 < k < n
        return (Binomial_Coefficient(n-1, k-1)+Binomial_Coefficient(n-1, k));//nCk = n-1Ck-1 + n-1Ck
    }
    else{
        printf("0 < k < nではありません");
    }
}