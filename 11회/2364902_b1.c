#include <stdio.h>
#include <stdlib.h>

void convert(int m, int n);
void number_to_char(int n);

int main(void){
    int input_number = 0;
    int number = 0;
    
    while(1){
        printf("10進数の正数を入力してください ( 0 以下で終了 ):");
        scanf("%d", &input_number);
        
        if(input_number <= 0){
            break;
        }
        else{
            while(1){
                printf("n 進数に変換しますか? ( 2 ≦ n ≦ 16 ) :");
                scanf("%d", &number);
                
                if(2 <= number && number <= 16){
                    break;
                }
                else{
                    printf("2 ≦ n ≦ 16 ではありません\n");
                    continue;
                }
            }
            convert(input_number, number);
            printf("\n\n");
        }
    }
    printf("処理を終了します\n");
    
    return 0;
}

void convert(int m, int n) {
    if (m == 0) { // when m / m == 0
        return;
    }
    int remainder = m % n;//each digit
    convert(m / n, n);//recursive 
    if (remainder < 10) {
        printf("%d", remainder);
    } else {
        printf("%c", remainder - 10 + 'a');//when number is over 10
    }
}
