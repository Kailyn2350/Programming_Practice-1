#include <stdio.h>
#include <math.h>

#define SCALE_OF_VECTOR(v) (sqrt(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2)))


struct vector{
    double x;
    double y;
    double z;
};

double scale_of_vector(struct vector* arr); 
double inner_product_vector(struct vector* arr1, struct vector* arr2);

int main(void){
    struct vector v1 = {2.0, 3.0, 4.0};
    struct vector v2 = {5.0, 6.0, 7.0};
    
    printf("Vector 1 : ( %lf, %lf, %lf )\n", v1.x, v1.y, v1.z);
    printf("Vector 2 : ( %lf, %lf, %lf )\n", v2.x, v2.y, v2.z);
    printf("\n");
    
    double scale_cos = 0;
    scale_cos = (inner_product_vector(&v1, &v2) / ((SCALE_OF_VECTOR(v1) * SCALE_OF_VECTOR(v2)))); //calculation of cos
    
    printf("φ[deg] = %lf", ((double)acos(scale_cos) * 180) / M_PI); //deg = (rad * 180) / pi;
}

double inner_product_vector(struct vector* arr1, struct vector* arr2){
    double inner_result = arr1->x * arr2->x + arr1->y * arr2->y + arr1->z * arr2->z;
    return inner_result;
}