#include <stdio.h>

void print_comma(unsigned int n);

int main(void){
    unsigned int number = 0;
    
    printf("n = ");
    scanf("%u", &number);
    if(number < 1000){//入力された数字が3桁の場合
        printf("%u", number);
    }
    else{//3桁の以上の場合
        print_comma(number);
    }
    return 0;

}
void print_comma(unsigned int n){
    int Remainder[] = {-1, -1};//余りを保存する配列
    
    for(int i = 0; n/1000 >= 1000; i++){//余りを保存する作業
            Remainder[i] = n%1000;
            n /= 1000;
    }
    printf("%d,%03d", n/1000, n%1000);//最上位の桁と余りを出力
    
    if(Remainder[1] != -1){//消えた余りが二つの場合の出力
        printf(",%03d,%03d", Remainder[1], Remainder[0]);
    }
    else if(Remainder[0] != -1){//消えた余りが一つの場合の出力
        printf(",%03d",Remainder[0]);
    }
    
}