#include <stdio.h>

struct vector{//3dimensions vector
    double x;
    double y;
    double z;
};

void outer_product(struct vector arr1[], struct vector arr2[]);//outer_product function

int main(void){
    struct vector v1;
    struct vector v2;
    printf("3次元ベクトルAのｘｙｚの値を入力してください。（ｘｙｚ）：");//input vector A value
    scanf("%lf %lf %lf", &v1.x, &v1.y, &v1.z);
    printf("3次元ベクトルBのｘｙｚの値を入力してください。（ｘｙｚ）：");//input vector B value
    scanf("%lf %lf %lf", &v2.x, &v2.y, &v2.z);
    printf("ベクトル A : %lf %lf %lf\n", v1.x, v1.y, v1.z);//print vector A
    printf("ベクトル B : %lf %lf %lf\n", v2.x, v2.y, v2.z);
    printf("ベクトルAとベクトルBの外積：");
    outer_product(&v1, &v2);
    
    return 0;
}

void outer_product(struct vector arr1[], struct vector arr2[]){
    printf("%lf ", (arr1->y * arr2->z) - (arr1->z * arr2->y));
    printf("%lf ", (arr1->z * arr2->x) - (arr1->x * arr2->z));
    printf("%lf ", (arr1->x * arr2->y) - (arr1->y * arr2->x));
}