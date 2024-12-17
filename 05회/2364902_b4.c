#include <stdio.h>


double inner_product(double a[][10], int num);

int main(void){
    
    int n = 0;
    double arr[2][10];//declaration of max array 
    
    printf("ベクトルの次数 n （最大10）＝　");
    scanf("%d", &n);
    
    
    for(int i = 0; i < 2; i++){
        printf("ベクトル%dの入力 : \n", i+1);
        for(int j = 0; j < n; j++){
            scanf("%lf", &arr[i][j]);
        }
    }
    
    
    printf("内積＝%lf", inner_product(arr, n));
    
    return 0;
}

double inner_product(double a[][10], int num){
    double result = 0.0;
    for(int i = 0; i < num; i++){
        result += (a[0][i] * a[1][i]);//calculation of inner product
    }
    return result;
}