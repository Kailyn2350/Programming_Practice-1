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
void print_path();

int main(void){
    data[1][1] = 0;//initializing start point
    if(find_path(0, 1, 1)){
        print_path();//when program find goal print path
    }
    else{
        printf("解は見つかりませんでした\n");
    }
    return 0;
}

int find_path(int n, int x, int y){
    if(data[y][x] == 9){//when program find path to goal
        return 1;
    }
    
    if(data[y][x] == 0){//when position is 0
        data[y][x] = 1;

        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        
        for(int i = 0; i < 4; i++){
            if(find_path(n + 1, x+dx[i], y+dy[i])){
                return 1;
            }
        }
        
        //back tracking
        data[y][x] = 0;
    }
    
    return 0;
}

void print_path(){
    int x, y;
    
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
