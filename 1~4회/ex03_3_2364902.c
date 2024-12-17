#include <stdio.h>
#include <math.h>

struct vector{
    double x;
    double y;
    double z;
};

double scale_of_vector(struct vector* arr); 
double inner_product_vector(struct vector* arr1, struct vector* arr2);

int main(void){
    struct vector v1 = {1.0, 2.0, 3.0};
    struct vector v2 = {4.0, 5.0, 6.0};
    
    printf("Vector 1 : ( %lf, %lf, %lf )\n", v1.x, v1.y, v1.z);
    printf("Vector 2 : ( %lf, %lf, %lf )\n", v2.x, v2.y, v2.z);
    printf("\n");
    
    double scale_cos = 0;
    scale_cos = (inner_product_vector(&v1, &v2) / ((scale_of_vector(&v1) * scale_of_vector(&v2)))); //calculation of cos
    
    printf("φ[deg] = %lf", ((double)acos(scale_cos) * 180) / M_PI); //deg = (rad * 180) / pi;
}

double scale_of_vector(struct vector* arr){
    double scale_result = sqrt(pow(arr->x, 2)+pow(arr->y, 2)+pow(arr->z, 2));//(x^2 + y^2 + z^2)^(1/2)
    return scale_result;
}

double inner_product_vector(struct vector* arr1, struct vector* arr2){
    double inner_result = arr1->x * arr2->x + arr1->y * arr2->y + arr1->z * arr2->z;
    return inner_result;
}