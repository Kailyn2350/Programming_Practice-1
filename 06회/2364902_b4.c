#include <stdio.h>
#define EOS '\0'

int count_key(char a[], char b[]);

int main(void){
    char str_a[100];//User input str
    char str_b[100];//key str
    
    printf("文字列 a = ");
    gets(str_a);//input str_a
    printf("文字列 b = ");
    gets(str_b);//input str_b
    
    printf("文字列 a の中に \"%s\" は %d 個ありました。", str_b, count_key(str_a, str_b));//call count_key fuction
    
    return 0;
}

int count_key(char a[], char b[]){
    int len = 0;//length of key str
    int count = 0;
    
    for(int i = 0; b[i] != EOS; i++){//to count length of key str
        len++;
    }
    for(int i = 0; a[i] != EOS; i++){
        int same_word_count = 0;//same word count value initialization every Every time repeat it
        for(int j = 0; b[j] != EOS; j++){
            if(a[i+j] == b[j]){//when program meet same word
                same_word_count++;
            }
            else if(a[i] != b[j]){
                break;
            }
        }
        if(same_word_count == len){//if same word count value and len is same, str_b is exsist in str_a
            i += (len - 1);//if str_b is exsist in str_a, index move
            count++;
        }
    }
    return count;
}