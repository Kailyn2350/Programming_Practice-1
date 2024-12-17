#include <stdio.h>
#include <stdlib.h>

struct student{
    int num;//student number
    char name[20];//name
    int score;//score
};

void quickSort(struct student d[], int left, int right);
void printout(struct student d[], int n);

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
    printf("ソート前\n");
    printout(d, n);//before sort
    
    quickSort(d, 0, n-1);
    printf("ソート後\n");
    printout(d, n);//after sort
}

void printout(struct student d[], int n){
    for(int i = 0; i < n; i++){
        printf("%4d %-20s %3d\n", d[i].num, d[i].name, d[i].score );
    }
    
}

void quickSort(struct student d[], int left, int right){
	int l = left, r = right;
	int pivot = d[(left+right) / 2].score;//set up center index to pivot
	struct student temp;//temp struct to replace each struct
	
	for(;l <= r;){
	    for(;d[l].score > pivot; l++){//find bigger score index than pivot
	        
	    }
	    for(;d[r].score < pivot; r--){//find smaller score index than pivot
	        
	    }
	    if(l <= r){//when bigger score index is smaller than smaller score index, replace each other.
	        temp = d[l];
	        d[l] = d[r];
	        d[r] = temp;
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