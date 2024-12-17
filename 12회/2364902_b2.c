#include <stdio.h>

#define NUM 5 //the number of position

// 0, 1, 2, 3, 4
//set current position 0 and moveable position 1
int graph[NUM][NUM] = {
    {0, 1, 1, 0, 0}, // 0 -> 1, 0 -> 2
    {1, 0, 1, 1, 1}, // 1 -> 0, 1 -> 2, 1 -> 3, 1 -> 4
    {1, 1, 0, 1, 0}, // 2 -> 0, 2 -> 1, 2 -> 3
    {0, 1, 1, 0, 1}, // 3 -> 1, 3 -> 2, 3 -> 4
    {0, 1, 0, 1, 0}  // 4 -> 1, 4 -> 3
};

int cheak[NUM] = {0}; // cheak visit or not
int path[NUM]; //save path
int pathIndex = 0;
void find_path(int point, int end);

int main() {
    printf("0から4に至る経路:\n");
    find_path(0, 4);
    return 0;
}

void find_path(int point, int end) {
    cheak[point] = 1; // current point set 1
    path[pathIndex] = point; //set path current point
    pathIndex++;

    if (point == end) { // end conditions
        for (int i = 0; i < pathIndex; i++) {//print path
            printf("%d ", path[i]);
        }
        printf("\n");
    } else {
        for (int i = 0; i < NUM; i++) {
            if (graph[point][i] == 1 && !cheak[i]) { //when i position is moveable and not visited point
                find_path(i, end);//recursion
            }
        }
    }

    pathIndex--;
    cheak[point] = 0;//back tracking
}