#include <stdio.h>

int str_len(char a[], char b[]);

int main(){
    char str[128];      //input arrangement
    char str_copy[128];    //output arrangement
    
    printf("Input : ");
    gets (str);
    
    int l = str_len(str, str_copy);
    
    printf("Output : ");
    puts(str_copy);    //print str_copy
    
    printf("length = %d\n", l);     //print length of str
    
    
    
    return 0;
}

int str_len(char a[], char b[]){
    int i;
    for(i = 0; a[i] != '\0'; i++){      //str copy
        b[i] = a[i];
    }
    
    b[i] = '\0';    //the last letter \0 put into b[i]
    
    return i;       //i return
}