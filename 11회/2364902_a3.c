#include <stdio.h>

// array of expressions as strings
const char* expressions[] = {
    "3 - 3! + 4", //1
    "3 + 3 - 4", //2
    "3^3 - 4!", //3
    "3 - 3 + 4", //4
    "3 × 3 - 4", //5
    "3^3 - 4! + 3^3 - 4!", //6
    "3 × 3 - √4", //7
    "3! + 3! - 4", //8
    "33 - 4!", //9
    "3 × 3 + √4 - 3 - 3! + 4"//10
};

void Hanshin(int n);

int main(void) {
    int input = 0;
    
    while(1){
        printf("「 0 」以外の任意の自然数を入力してください: ");
        scanf("%d", &input);
        
        if(input == 0){
            break;
        }
    
        Hanshin(input);
        
        printf("\n");
    }

    
    return 0;
}

void Hanshin(int n){
    int remain = 0;
    int count = 0;//count for digit position
    
    if(n <= 10 && n > 0){
        printf("%d = %s", n, expressions[n - 1]);
    }
    else{
        while(n % 10 != 0 || n / 10 != 0){
            remain = n % 10;
            count++;
            if(remain == 0){
                
            }
            else if(count == 1){
                printf("%d = (%s)", n, expressions[remain - 1]);//print first digit
            }
            else if(count == 2){//print second digit
                printf(" + (%s) × (%s)", expressions[remain - 1], expressions[9]);
            }
            else{//print after digit
                printf(" + (%s) × (%s) ^ (%s)", expressions[remain - 1], expressions[9], expressions[count - 2]);
            }
            n = n / 10;
        }
    }
}