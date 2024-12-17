#include <stdio.h>
#include <stdbool.h>

#define N 9

int board[N][N] = {
    {0,7,5,0,0,3,0,8,4},
    {0,0,0,0,6,0,0,0,0},
    {4,1,3,0,8,0,0,0,0},
    {7,8,0,2,0,6,4,0,3},
    {2,0,1,3,0,9,0,6,8},
    {0,0,4,0,7,0,9,5,0},
    {1,0,8,0,2,4,5,0,9},
    {9,4,6,5,0,7,0,2,1},
    {5,2,7,9,1,0,3,4,6}
};

void print_board();
int check(int row, int col, int num);
int solve_sudoku();

int main(void){
    printf("問題\n");
    print_board();
    
    if (solve_sudoku()) {
        printf("\n答え\n");
        print_board();
    } else {
        printf("\n答えがない問題です\n");
    }
    
    return 0;
}

void print_board() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            printf("%d ", board[i][j]);
            if((j+1) % 3 == 0){
                printf(" ");
            }
        }
        printf("\n");
        if((i+1) % 3 == 0){
            printf("\n");
        }
    }
}

int check(int row, int col, int num){
    for(int i = 0; i < N; i++){
        if(board[row][i] == num){//check same number on the same row
            return 0;
        }
    }
    
    for(int i = 0; i < N; i++){
        if(board[i][col] == num){//check same number on the same col
            return 0;
        }
    }
    
    //check same number on the  3 x 3 
    int start_row = row - row % 3;//set first position in 3 X 3
    int start_col = col - col % 3;//set first position in 3 X 3
    for (int i = start_row; i < start_row + 3; ++i) {
        for (int j = start_col; j < start_col + 3; ++j) {
            if (board[i][j] == num) {
                return 0;
            }
        }
    }
}

int solve_sudoku(){
    int row, col = 0;
    int is_empty = 0;
    
    //find blank
    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            if (board[row][col] == 0) {
                is_empty = 1;
                break;
            }
        }
        if (is_empty) {
            break;
        }
    }
    
    if (!is_empty) {
        return 1;
    }
    
    //try to 1 ~ 9
    for (int num = 1; num <= N; num++) {
        if (check(row, col, num)) {//when check is ok fill blank to number
            board[row][col] = num;
            
            //to move on to find a blank
            if (solve_sudoku()) {
                return 1;
            }
            
            //when chack is faill restore blank
            board[row][col] = 0;
        }
    }
}
