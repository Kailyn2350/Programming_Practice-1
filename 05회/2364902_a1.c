#include <stdio.h>


double inner_product_matrix(double a[], double b[], int num);
double inner_product_pointer(double *x, double *y, int num);

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
    
    
    printf("内積（配列）＝%lf\n", inner_product_matrix(arr[0], arr[1], n));
    printf("内積（ポインタ）＝%lf", inner_product_pointer(arr[0], arr[1], n));
    
    return 0;
}
double inner_product_matrix(double x[], double y[], int num){
    double result = 0.0;
    for(int i = 0; i < num; i++){
        result += x[i] * y[i];//calculation of inner product by using matrix
    }
    return result;
}
double inner_product_pointer(double *x, double *y, int num){
    double result = 0.0;
    for(int i = 0; i < num; i++){
        result += (*x++) * (*y++);//calculation of inner product by using pointer
    }
    return result;
}