#include <stdio.h>

static int arr[] = {-1, -1};//余りを保存する変数要素がない時の識別数字-1
static int count = 0;//何回再帰関数を読んだか確認する変数

int call(int n);

int main(void){
    int number = 0;
    
    printf("n = ");
    scanf("%d", &number);
    
    if(number < 1000){
        printf("%d", number);
        return 0;
    }
    else{
        call(number);
    }
    
    
}

int call(int n){
    if(n/1000 < 1000){
        if(n%1000 < 10){//余りが1桁の場合
            printf("%d,00%d", n/1000, n%1000);
        }
        else if(n%1000 < 100){//余りが2桁の場合
            printf("%d,0%d", n/1000, n%1000);
        }
        else{//余りが33桁の場合
            printf("%d,%d", n/1000, n%1000);
        }
        //もし、2,147,483,647の場合は
        if(arr[1] != -1){//483の部分
            if(arr[1]/10 == 0){//消えた余りが1桁の場合
                printf(",00%d",arr[1]);
            }
            else if(arr[1]/100 == 0){//消えた余りが2桁の場合
                printf(",0%d", arr[1]);
            }
            else{//消えた余りが3桁の場合
                printf(",%d", arr[1]);
            }
        }
        if(arr[0] != -1){//647の部分
            if(arr[0]/10 == 0){
                printf(",00%d",arr[0]);
            }
            else if(arr[0]/100 == 0){
                printf(",0%d", arr[0]);
            }
            else{
                printf(",%d", arr[0]);
            }
        }
    }
    else{//消える余りが存在するとき
        arr[count] = n%1000;//保存
        count++;
        return call(n/1000);
    }
}