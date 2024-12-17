#include <stdio.h>
#include <stdlib.h>

struct student{
    int num;
    char name[20];
    int score;
};

void simple_sort(struct student d[], int n);
void printout(struct student d[], int n);

int main (int argc, char *argv[]){
    int n = 0;
    FILE *fp = fopen(argv[1], "r");//open argv to reading type
    if(fp == NULL){//when program fail to open file
        printf("Error!!\n");
        return 1;
    }
    struct student d[3000];
    while ( fscanf( fp, "%d %s %d", &d[n].num, d[n].name, &d[n].score ) != EOF ){//count number of data
        n++;
    }
    
    printout(d, n);//before sort
    
    simple_sort(d, n);
    printf("-------------------------------------------------------\n");
    printout(d, n);//after sort
}

void printout(struct student d[], int n){
    for(int i = 0; i < n; i++){
        printf("%4d %-20s %3d\n", d[i].num, d[i].name, d[i].score );
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