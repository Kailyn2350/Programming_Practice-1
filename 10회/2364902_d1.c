#include <stdio.h>

int count = 0;

int fibo_recursive(int n);
int fibo_tail_recursive(int n, int a, int b);
int fibo_loop(int n);

int main(void){
    int n = 0;
    int result = 0;
    printf("正数ｎを入力してください\n");
    printf("n = ");
    scanf("%d", &n);
    if(n < 0){//when user input negative number
        printf("ｎは正数ではありません");
        return 0;
    }
    count = 0;//variable for count call_number and loop_number
    result = fibo_recursive(n);//call double recursive
    printf("二重再帰：計算結果：%d, 呼び出し回数：%d\n", result, count);
    count = 0;
    result = fibo_tail_recursive(n, 0, 1);//call tail recursive
    printf("未尾再帰：計算結果：%d, 呼び出し回数：%d\n", result, count);
    count = 0;
    result = fibo_loop(n);//call loop
    printf("ループ：計算結果：%d, 繰り返し回数：%d\n", result, count);
    
    return 0;
}

int fibo_recursive(int n){
    count++;//when call function
    if(n == 0){//f(0) == 0
        return 0;
    }
    else if(n == 1){//f(1) == 1
        return 1;
    }
    else{//f(n) = f(n-1) + f(n-2)
        return fibo_recursive(n-1) + fibo_recursive(n-2);
    }
}

int fibo_tail_recursive(int n, int now_number, int after_number){
    count++;
    if (n == 0) {
        return now_number;//print now_number
    }
    else {
        return fibo_tail_recursive(n-1, after_number, now_number+after_number);//return n-1, number, after number
    }
}

int fibo_loop(int n){
    int result = 0;
    int before_num = 1;
    int num = 1;
    for(int i = 0; i < n; i++){
        count++;
        if(i == 0 || i == 1){
            result = 1;
        }
        else{
            result = before_num + num//result = n-1 + n
            before_num = num;//n-1 = n
            num = result;//n = (n+1)(result)
        }
    }
    return result;
}