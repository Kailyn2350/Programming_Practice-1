#include <stdio.h>
#define BUFSIZE 256

int main(void){
    char buffer[BUFSIZE];//char variable to store each string
    int comment_key = 0; // 0 = False, 1 = True
    
    for(int i = 0; fgets(buffer, BUFSIZE, stdin) != NULL; i++){//until program reach End Of File
        for(int j = 0; buffer[j] != '\n'; j++){//until program reach end of string row
            if(buffer[j] == '/' && buffer[j+1] == '*'){//when slash appear continuously
                comment_key = 1;
            }
            if(comment_key == 1 && buffer[j-1] == '*' && buffer[j] == '/'){//when asterisk and slash appear continuously and comment_key is True
                fprintf(stdout, "/\n");//before comment_key change 0. print slash and \n
                comment_key = 0;//comment_key False
            }
            if(comment_key == 1){//only print letter when comment_key is True
                fprintf(stdout, "%c", buffer[j]);
            }
        }
        if(comment_key == 1){//when string is over, print \n
            fprintf(stdout, "\n");
        }
    }
    return 0;
}
