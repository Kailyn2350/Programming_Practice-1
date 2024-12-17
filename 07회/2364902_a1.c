#include <stdio.h>
#define BUFSIZE 256

int main(void){
    char buffer[BUFSIZE];//char variable to store each string
    int comment_key = 0; // 0 = False, 1 = True
    
    for(int i = 0; fgets(buffer, BUFSIZE, stdin) != NULL; i++){//until program reach End Of File
        for(int j = 0; buffer[j] != '\n'; j++){//until program reach end of string row
            if(buffer[j] == '/' && buffer[j+1] == '/'){//when slash appear continuosly
                buffer[j] = '\n';//replace letter into \n
                for(int n = j+1; buffer[n] != '\n'; n++){//replace comment into NULL
                    buffer[n] = NULL;
                }
            }
            if(buffer[j] == '/' && buffer[j+1] == '*'){//when slash appear continuously
                comment_key = 1;
                continue;
            }
            if(comment_key == 1 && buffer[j] == '*' && buffer[j+1] == '/'){//when asterisk and slash appear continuously
                comment_key = 0;//comment_key False
                j++; // skip the next character
                continue;
            }
            if(comment_key == 0){//only print letter when comment_key is False
                fprintf(stdout, "%c", buffer[j]);
            }
        }
        if(comment_key == 0){
            fprintf(stdout, "\n");
        }
    }
    return 0;
}
