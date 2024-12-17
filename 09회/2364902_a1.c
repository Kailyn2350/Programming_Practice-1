#include <stdio.h>
#include <stdlib.h>

static int compare_count = 0;
static int change_count = 0;

struct student{
    int num;
    char name[20];
    int score;
};

void simple_sort(struct student d[], int n);
int printout(struct student d[], int n, char name[]);
void merge(struct student d[], int left, int mid, int right);
void merge_sort(struct student d[], int left, int right);

int main (int argc, char *argv[]){
    int n = 0;
    FILE *fp = fopen(argv[1], "r");//open argv to reading type
    if(fp == NULL){//when program fail to open file
        printf("Error!!\n");
        return 1;
    }
    struct student d[3000];
    fscanf(fp, "%d %s %d", &d[n].num, d[n].name, &d[n].score);//scanf argv file
    while ( fscanf( fp, "%d %s %d", &d[n].num, d[n].name, &d[n].score ) != EOF ){//count number of data
        n++;
    }
    
    merge_sort(d, 0, n-1);
    printout(d, n, argv[2]);//after sort
    
    fclose(fp);
    
    printf("比較回数：%d\n入れ替え回数：%d", compare_count, change_count);
    
    return 0;
}

int printout(struct student d[], int n, char name[]){
    FILE *fp1 = fopen(name, "w");
    if(fp1 == NULL){//when program fail to open file
        printf("Error!!\n");
        return 1;
    }
    for(int i = 0; i < n; i++){
        fprintf(fp1, "%4d %-20s %3d\n", d[i].num, d[i].name, d[i].score );
    }
    
}

void simple_sort(struct student d[], int n){
    struct student temp;//temporary struct to change each other
    
    for(int i = 0; i < n-1; i++){//to find max score n times
        int max_score = d[i].score;//initialize max_number by putting each first index in max_number
        int max_number = i;//max_number initialization
        for(int j = i+1; j < n; j++){//to find max score and max score number
            if(d[j].score > max_score){
                max_score = d[j].score;
                max_number = j;
            }
        }
        temp = d[i];//change index struct to max_number struct
        d[i] = d[max_number];
        d[max_number] = temp;
    }
}


void merge(struct student d[], int left, int mid, int right) {
    int i = left, j = mid + 1, k = left;
    struct student temp[3000];
    
    //merge split-aligned d[]
    for(;i <= mid && j <= right; compare_count++) {
        if(d[i].score >= d[j].score) {
            temp[k++] = d[i++];
        } else {
            temp[k++] = d[j++];
        }
    }
    //copy remained data
    for(;i <= mid;){
        temp[k++] = d[i++];
    }
    //copy remained data
    for(;j <= right;){
        temp[k++] = d[j++];  
    }

    //copy temp[] to b[] again
    for(int a = left; a <= right; a++) {
        change_count++;
        d[a] = temp[a];
    }
}

void merge_sort(struct student d[], int left, int right) {
    int mid;
    if(left < right) {
        mid = (left + right) / 2;//set middle index
        merge_sort(d, left, mid);//sort left side
        merge_sort(d, mid + 1, right);//sort right side
        merge(d, left, mid, right);//aligned
    }
}


