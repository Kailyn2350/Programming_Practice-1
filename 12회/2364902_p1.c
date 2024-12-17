#include <stdio.h>
#define TRUE 1
#define FALSE 0

int check[10] = {0};
int sel[4];

void try(int i);
int div(void);
void prt(void);

int main(void){
    printf("ab, cd\n");
    try(0); //strat recursive
    return 0;
}

void try(int index) {
    if (index == 4) {//when index is 4. when sel[] fill all digit
        if (div()) { //check ab is cd * 3
            prt(); //print when div() is true
        }
        return;
    }
    
    for (int i = 1; i <= 9; ++i) { //select 1 ~ 9
        if (check[i] == FALSE) { // if it's a number that hasn't been used yet
            check[i] = TRUE;  // when i is ok mark "used"
            sel[index] = i;     // i store in sel[]
            try(index + 1); // recursive next index
            check[i] = FALSE; // back tracking
        }
    }
}

int div(void) {
    // set ab and cd
    int a = sel[0], b = sel[1], c = sel[2], d = sel[3];
    int ab = a * 10 + b;
    int cd = c * 10 + d;
    
    // check
    return (ab == cd * 3);
}

void prt(void) {
    // print cd, ab
    printf("%d%d, %d%d\n", sel[0], sel[1], sel[2], sel[3]);
}
