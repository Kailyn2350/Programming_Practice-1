#include <stdio.h>
#define NUM 10//number of data

void printout(int d[], int n);
void bubble_sort(int d[], int m, int n);

int main() {
    int a[NUM] = {9, 1, 3, 7, 0, 5, 4, 2, 8, 6};

    printf("整列前: ");
    printout(a, NUM);

    int first_index = 4; // start index
    int end_index = 9; // end index

    bubble_sort(a, first_index, end_index);

    printf("整列後: ");
    printout(a, NUM);

    return 0;
}

void printout(int d[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", d[i]);
    }
    printf("\n");
}

void bubble_sort(int d[], int m, int n) {
    for (int i = m; i < n; i++) {//start index = m, end index = n
        for (int j = m; j < n - i + m; j++) {
            if (d[j] > d[j + 1]) {//compare n index data and n+1 index data
                int temp = d[j];//change each other
                d[j] = d[j + 1];
                d[j + 1] = temp;
            }
        }
    }
}