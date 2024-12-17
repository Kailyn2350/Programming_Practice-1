#include <stdio.h>
#include <math.h>

double inner_product_matrix(double a[], double b[], int num);
double trans_radian_into_angle(double a);

int main(void){
    
    int n = 0;
    double IP = 0.0;
    double Value_cos, Value_radian = 0.0;
    double scalar_arr0, scalar_arr1;
    double arr[2][10];//declaration of max array 
    
    printf("ベクトルの次数 n （最大10）＝　");
    scanf("%d", &n);
    
    for(int i = 0; i < 2; i++){
        printf("ベクトル%dの入力 : \n", i+1);
        for(int j = 0; j < n; j++){
            scanf("%lf", &arr[i][j]);
        }
    }
    
    IP = inner_product_matrix(arr[0], arr[1], n);//inner product calculation of vector0 and vector 1
    
    for(int i = 0; i < n; i++){//scalar calculation of vector 0
        scalar_arr0 += pow(arr[0][i], 2);
    }
    scalar_arr0 = sqrt(scalar_arr0);
    
    for(int i = 0; i < n; i++){//scalar calculation of vector 1
        scalar_arr1 += pow(arr[1][i], 2);
    }
    scalar_arr1 = sqrt(scalar_arr1);
    
    Value_cos = IP / (scalar_arr0 * scalar_arr1);//cos calculation
    
    Value_radian = acos(Value_cos);
    
    printf("θ＝%lf", trans_radian_into_angle(Value_radian));
    
    return 0;
}
double inner_product_matrix(double x[], double y[], int num){
    double result = 0.0;
    for(int i = 0; i < num; i++){
        result += x[i] * y[i];//calculation of inner product by using matrix
    }
    return result;
}
double trans_radian_into_angle(double a){
    return (a * (180 / M_PI));

}