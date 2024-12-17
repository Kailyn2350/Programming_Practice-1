#include <stdio.h>
#define STR_LEN 100
#define EOS '\0'

int word_copy(char a[], char b[]);

static char *Ptr;

int main(void){
    char input_str[STR_LEN];
    char copy_str[STR_LEN];
    int length;
    printf("Input : ");
    gets(input_str);
    
    Ptr = input_str; // initialize Ptr with input_str
    
    for(int i = 0;;i++){
        if(i == 0){//when first time
            length = word_copy(copy_str, input_str);//input length of first str and call word_copy function
        }
        else if(i > 0){//after first time
            length = word_copy(copy_str, NULL);
            if(length == 0){
                break;
            }
        }
        else{
            printf("Error!!");
            return 0;
        }
        printf("Output : ");
        for(int j = 0; copy_str[j] != EOS; j++){//print copy_str
            printf("%c", copy_str[j]);
        }
        printf(", length = %d\n", length);   
    }
}

int word_copy(char a[], char b[]){
    if(b == NULL){
        b = Ptr;
    }
    if(*Ptr == EOS){
        return 0;
    }
    int i = 0;
    int count = 0;//count value in order to count length of str
    for(;; i++){
        if(*(b+i) == ' ' || *(b+i) == EOS){
            if(count > 0){//when program meet second blank str
                break;
            }
            else if(count == 0){//when program meet first blank str
                continue;
            }
        }
        else if(*(b+i) != ' '){
            a[count] = *(b+i);//to input first index in a
            count++;
        }
        
    }
    Ptr = b+i+1;
    a[count] = EOS;
    return count;
}
