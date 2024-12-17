#include <stdio.h>
#define BUFSIZE 256

int main(void){
    char buffer[BUFSIZE];//char variable to store each string
    
    for(int i = 0;fgets(buffer, BUFSIZE, stdin) != NULL; i++){//untill program reach End Of File
        for(int j = 0; buffer[j] != '\n'; j++){//untill program reach end of string row
            if(buffer[j] == '/' && buffer[j+1] == '/'){//when slash appear continuosly
                buffer[j] = '\n';//replace letter into \n
                for(int n = j+1; buffer[n] != '\n'; n++){//replace comment into NULL
                    buffer[n] = NULL;
                }
            }
        }
        fprintf(stdout, "%s", buffer);
    }
    return 0;
}