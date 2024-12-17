#include <stdio.h>

void input_mat(double arr[][2]);
void print_mat(double arr[][2]);
double inverse(double arr_a[][2], double arr_b[][2]);

int main(void){
    double a[2][2];
    double b[2][2];
    
    printf("2 x 2 の行列の要素の値を入力してください\n");
    input_mat(a);
    print_mat(a);
    
    double matrix_formula_a = inverse(a, b);
    
    if(matrix_formula_a == 0){//when inverse matrix has not existed
        printf("の逆行列は存在しない。");
    }
    else{//when inverse matrix has existed
        printf("の逆行列は\n");
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++){
                printf("%lf ", b[i][j]);
            }
            printf("\n");
        }
    }
}

void input_mat(double arr[][2]){
    for(int i = 0; i < 2; i++){
        for(int  j = 0; j < 2; j++){
            printf("a[%d][%d] = ", i, j);
            scanf("%lf", &arr[i][j]);
        }
    }
    
}
void print_mat(double arr[][2]){
    for(int i = 0; i < 2; i++){
        for(int  j = 0; j < 2; j++){
            printf("%lf ", arr[i][j]);
        }
        printf("\n");
    }
}

double inverse(double arr_a[][2], double arr_b[][2]){
    double matrix_formula = (arr_a[0][0] * arr_a[1][1]) - (arr_a[0][1]*arr_a[1][0]);
    if(matrix_formula != 0){
        arr_b[0][0] = (1/matrix_formula) * arr_a[1][1];
        arr_b[0][1] = (1/matrix_formula) * -arr_a[0][1];
        arr_b[1][0] = (1/matrix_formula) * -arr_a[1][0];
        arr_b[1][1] = (1/matrix_formula) * arr_a[0][0];
    }
    else{
        return matrix_formula;
    }
}