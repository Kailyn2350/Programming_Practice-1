#include <stdio.h>
#include <stdlib.h>

static int compare_count = 0;
static int change_count = 0;

struct student{
    int num;//student number
    char name[20];//name
    int score;//score
};

void quickSort(struct student d[], int left, int right);
void printout(struct student d[], int n, char name[]);

int main(int argc, char *argv[]){
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
    
    quickSort(d, 0, n-1);
    printout(d, n, argv[2]);//after sort
    
    fclose(fp);
    
    printf("比較回数：%d \n入れ替え回数：%d", compare_count, change_count);
    
    return 0;
}

void printout(struct student d[], int n, char name[]){
    FILE *fp1 = fopen(name, "w");
    for(int i = 0; i < n; i++){
        fprintf(fp1, "%4d %-20s %3d\n", d[i].num, d[i].name, d[i].score );
    }
    fclose(fp1);
}

void quickSort(struct student d[], int left, int right){
	int l = left, r = right;
	int pivot = d[(left+right) / 2].score;//set up center index to pivot
	struct student temp;//temp struct to replace each struct
	
	for(;l <= r;){
	    for(;d[l].score > pivot; l++){//find bigger score index than pivot
	        compare_count++;
	    }
	    for(;d[r].score < pivot; r--){//find smaller score index than pivot
	        compare_count++;
	    }
	    if(l <= r){//when bigger score index is smaller than smaller score index, replace each other.
	        temp = d[l];
	        d[l] = d[r];
	        d[r] = temp;
	        change_count++;
	        l++;//move next index
	        r--;//move next index
	    }
	}
	if(left < r){
	    quickSort(d, left, r);//new range left ~ r
	}
	if(l < right){
	    quickSort(d, l, right);//new range l ~ right
	}
}