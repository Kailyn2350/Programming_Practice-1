#include <stdio.h>

void fact_loop(int m);
int fact_rec(int m);

int main(void){
    int m;
    printf("input num : ");
    scanf("%d", &m);
    
    printf("factrial (loop) \n");
    fact_loop(m);
    printf("\n");
    printf("factrial (recursive call) \n");
    fact_rec(m);
    return 0;
}

void fact_loop(int m){
    for(int i = 0; i < m; i++){//loop of 0 ~ m-1
        printf("fact %d = ", i+1);
        int result = 1;//for print several result fact
        for(int j = i+1; j > 0; j--){//calculation of several fact
            result *= j;
        }
        printf("%d", result);
        printf("\n");
    }
}

int fact_rec(int m){
    int result = 1;
    if(m < 1){//when m is m < 1
        return 1;//return fact(0)(=1)
    }
    else{
        result = m*fact_rec(m-1);//recursive call by using result
        printf("fact %d = %d\n", m, result);//print several result of fact
        return result;//return result(recursive call). it is same of return m * fact_rec(m-1)
    }
}