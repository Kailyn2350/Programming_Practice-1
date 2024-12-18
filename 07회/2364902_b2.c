#include <stdio.h>

int main(int argc, char *argv[]){
    
    FILE* fp1 = fopen(argv[1], "r");//first file open
    FILE* fp2 = fopen(argv[2], "r");//second file open
    
    if(fp1 == NULL || fp2 == NULL){//Error massage when program can't open file
        printf("Error!!\n");
        return 0;
    }
    
    for(int i = 0;; i++){
        char letter_fp1 = 0;//first file letter
        char letter_fp2 = 0;//second file letter
        
        int result1 = fscanf(fp1, "%c", &letter_fp1);//first file letter save in letter_fp1 as char type
        int result2 = fscanf(fp2, "%c", &letter_fp2);//second file letter save in letter_fp2 as char type
        
        if(letter_fp1 != letter_fp2){//when program find different letter.
            printf("2つのファイルは異なります。\n");
            return 0;
        }
        
        if(result1 == EOF || result2 == EOF){//file1 or file2 reach End Of File
            break;
        }
    }
    fclose(fp1);//close file1
    fclose(fp2);//close file2
    
    printf("2つのファイルは同じです。\n");
    
    return 0;
}
