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

int path[NUM]; //cheak visit or not
int shortestPath[NUM]; // store shortest path
int shortestPathLength = NUM + 1; // initialize

void find_shortest_path(int point, int end, int length);

int main() {
    printf("0から4に至る最短経路:\n");
    find_shortest_path(0, 4, 0);

    if (shortestPathLength > NUM) {
        printf("最短経路が見つかりませんでした。\n");
    } else {
        printf("最短経路: ");
        for (int i = 0; i < shortestPathLength; i++) {
            printf("%d ", shortestPath[i]);
        }
        printf("\n");
    }

    return 0;
}

void find_shortest_path(int point, int end, int length) {
    path[length] = point; // add current point to the path
    length++;

    if (point == end) { // end condition
        if (length < shortestPathLength) { // update shortest path
            shortestPathLength = length;
            for (int i = 0; i < length; i++) {
                shortestPath[i] = path[i];
            }
        }
    } else {
        for (int i = 0; i < NUM; i++) {
            if (graph[point][i] == 1) { // when moveable position
                if (length < shortestPathLength) {//when he path length is shorter than the shortest path
                    // to avoid revisit
                    graph[point][i] = 0;
                    graph[i][point] = 0;

                    find_shortest_path(i, end, length);

                    // restore for back tracking
                    graph[point][i] = 1;
                    graph[i][point] = 1;
                }
            }
        }
    }

    length--;// back tracking
}
