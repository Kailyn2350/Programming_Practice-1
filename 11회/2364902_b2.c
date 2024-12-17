#include <stdio.h>
#define N 10

int data[N][N]={
  {8,8,8,8,8,8,8,8,8,8},
  {8,1,0,0,8,8,0,0,0,8},
  {8,0,8,0,0,0,0,8,0,8},
  {8,0,8,8,8,0,8,8,0,8},
  {8,0,0,8,8,0,0,8,0,8},
  {8,8,0,0,8,0,8,8,0,8},
  {8,0,8,0,8,0,0,8,0,8},
  {8,0,0,0,8,8,0,0,0,8},
  {8,8,8,0,0,0,0,8,0,8},
  {8,8,8,8,8,8,8,8,9,8}
};

int find_path(int n, int x, int y);
void print_path(int n);

int main(void){
    data[1][1] = 0;//initializing start point
    find_path(0, 1, 1);
    return 0;
}

int find_path(int n, int x, int y){
    if(data[y][x] == 9){
        print_path(n);//when program find goal print path
        return 0;
    }
    
    else if(data[y][x] == 0){
        data[y][x] = 1;

        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        
        for(int i = 0; i < 4; i++){
            find_path(n + 1, x+dx[i], y+dy[i]);
        }
        
        //back tracking
        data[y][x] = 0;
        return 0;
    }
    return 0;
}

void print_path(int n){
    int x, y;

    printf("%dで到着\n", n);//print step to goal
    
    for(y = 0; y < N; y++){
        for(x = 0; x < N; x++){
            if (data[y][x] == 8){//
                printf("■");
            }
            else if (data[y][x] == 0){
                printf("□");
            }
            else{
                printf("○");
            }
        }
        printf("\n");
    }
}
