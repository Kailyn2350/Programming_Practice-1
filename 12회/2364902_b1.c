#include <stdio.h>

#define TRUE 1
#define FALSE 0
#define NUM_ITEMS 5


struct item {
    char name[20];  // item name
    int weight;     // weight
};

struct item items[NUM_ITEMS] = {
    {"A", 7}, {"B", 4}, {"C", 5}, {"D", 6}, {"E", 3}
};

int sel[NUM_ITEMS] = { 0 };
int optSel[NUM_ITEMS] = { 0 };
int find_solution = 0;

void empty_set(int arr[], int n);
void try(int i, int total, int num, int max);
void copy_set(int arr1[], int arr2[], int num);
void print_answer(int arr[], int num);

int main(void) {
    int input = 0;
    empty_set(sel, NUM_ITEMS); //initialize of sel
    empty_set(optSel, NUM_ITEMS); //initialize of optSel
    
    printf("最大積載量を入力してください：");
    scanf("%d", &input);

    printf("最大積載量 %dt の荷物の組み合わせは以下の通り:\n", input);
    try(0, 0, NUM_ITEMS, input);
    if (find_solution == 0) {
        printf("適切な組み合わせが見つかりませんでした。\n");
    }

    return 0;
}

// initialize to empty
void empty_set(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = FALSE;
    }
}

// copy
void copy_set(int arr1[], int arr2[], int num) {
    for (int i = 0; i < num; i++) {
        arr1[i] = arr2[i];
    }
}

// add
void add_member(int arr[], int i) {
    arr[i] = TRUE;
}

// remove
void delete_member(int arr[], int i) {
    arr[i] = FALSE;
}

void try(int i, int result, int num, int max) {
    if (result == max) {//when program find solution combination
        find_solution++;
        print_answer(sel, num);
        return;
    }

    if (i >= num || result > max) {//end conditions
        return;
    }

    // when current item is including
    add_member(sel, i);
    try(i + 1, result + items[i].weight, num, max);

    // when current item is not including
    delete_member(sel, i);
    try(i + 1, result, num, max);
}

// print solution set
void print_answer(int arr[], int num) {
    for (int i = 0; i < num; i++) {
        if (arr[i]) {
            printf("%s:%dt ", items[i].name, items[i].weight);
        }
    }
    printf("\n");
}
