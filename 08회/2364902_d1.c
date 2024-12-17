#include <stdio.h>
#include <stdlib.h>

struct student{
    int num;
    char name[20];
    int score;
};

void simple_sort(struct student d[], int n);
void printout(struct student d[], int n, char file[]);

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
    
    fclose(fp);
    
    simple_sort(d, n);
    printout(d, n, argv[2]);//after sort
    
    printf("入力ファイル：%s\n", argv[1]);
    printf("出力ファイル：%s\n", argv[2]);
    
    return 0;
}

void printout(struct student d[], int n, char file[]){
    FILE *fp = fopen(file, "w");//open argv to writing type
    for(int i = 0; i < n; i++){
        fprintf(fp, "%d %s %d\n", d[i].num, d[i].name, d[i].score );
    }
    fclose(fp);
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
            else if(d[j].score == max_score && d[j].num < d[max_number].num){//when each score is same, transform the first index into an int type and compare it
                max_score = d[j].score;//when j index first index char of name str is bigger than max_number name index
                max_number = j;
            }
        }
        temp = d[i];//change index struct to max_number struct
        d[i] = d[max_number];
        d[max_number] = temp;
    }
}