#include <stdio.h>
#define NUM 256//Max str length

int main()
{
    char str [NUM];
    
    printf("文字列を入力してください（入力終了は [ Ctrl + D ] のみを入力）：\n");
    
    for(int i = 1; fgets(str, NUM, stdin) != NULL; i++ ){//Roop untill user push ctrl + D or reach End Of File.
        printf("%3d ", i);//Print space to express only 3 line
        fputs(str, stdout); //Print to moniter
    }
    return 0;
}
