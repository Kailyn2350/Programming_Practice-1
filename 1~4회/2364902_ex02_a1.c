#include <stdio.h>

int main(void){
    int number[10];//Input number
    int max, min = 0;//maximum number and minimum number
    
    for(int i = 0; i < 10; i++){
        printf("Input number %d : ", i+1);//Input information
        scanf("%d", &number[i]);
    }
    
    max = number[0];//initialization operation of mazximum variable
    min = number[0];//initialization operation of minimum variable
    
    for(int i = 0; i < 10; i++){
        if(number[i] > max){//confirmation of maximum
        max = number[i];
        }
        else if(number[i] < min){//confirmation of minimum
        min = number[i];
        }
    }
    
    printf("Max number is %d\n", max);
    printf("Min number is %d", min);
    
    return 0;
    
}