#include <stdio.h>
#define STR_LEN 100
#define EOS '\0' //declare End Of Str

int word_copy(char a[], char b[]);

int main(void){
    char input_str[STR_LEN];
    char copy_str[STR_LEN];
    
    printf("Input :");
    gets(input_str);
    
    
    int length = word_copy(copy_str ,input_str);//input length of first str and call word_copy function
    
    
    printf("Output : ");
    for(int i = 0; copy_str[i] != EOS; i++){//print copy_str
        printf("%c", copy_str[i]);
    }
    printf(", length = %d", length);
}

int word_copy(char a[], char b[]){
    int i;
    int count = 0;//count value in order to count length of str
    for(i = 0;; i++){
        if(b[i] == ' ' || b[i] == EOS){//a[i] == EOS is code to control when user input only one str
            if(count > 0){//when program meet second blank str
                break;
            }
            else if(count == 0){//when program meet first blank str
                continue;
            }
        }
        else if(a[i] != ' '){
            a[count] = b[i];
            count++;
        }
        
    }
    a[count] = EOS;//input EOS when input is over
    return count;
}