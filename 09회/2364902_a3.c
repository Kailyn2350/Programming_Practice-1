#include <stdio.h>
#include <sys/time.h>

int compare_count = 0;
int change_count = 0;

void printout(int d[], int n, char name[]);
void simple_count_time(char *input_file_name, char *output_file_name, int n);
void simple_sort(int d[], int n);
void bubble_count_time(char *input_file_name, char *output_file_name, int n);
void bubble_sort(int d[], int n);
void quick_count_time(char *input_file_name, char *output_file_name, int n);
void quick_sort(int d[], int left, int right);
void merge_count_time(char *input_file_name, char *output_file_name, int n);
void merge_sort(int d[], int left, int right);
void merge(int d[], int left, int mid, int right);


int main(int argc, char *argv[]){
    int data_number[] = {128, 1280, 12800};
    for(int i = 1; i <= 3; i++){
        printf("---------------データ数%d--------------------\n", data_number[i-1]);
        simple_count_time(argv[i], argv[i*2], data_number[i-1]);
        bubble_count_time(argv[i], argv[i*2], data_number[i-1]);
        quick_count_time(argv[i], argv[i*2], data_number[i-1]);
        merge_count_time(argv[i], argv[i*2], data_number[i-1]);
        printf("\n");
    }
    
    return 0;
}

void printout(int d[], int n, char name[]){
    FILE *fp1 = fopen(name, "w");
    for(int i = 0; i < n; i++){
        fprintf(fp1, "%5d\n", d[i]);
    }
    fclose(fp1);
}

void simple_count_time(char *input_file_name, char *output_file_name, int n){
    compare_count = 0;
    change_count = 0;
    int arr[n];
    FILE *fp = fopen(input_file_name, "r");
    for(int i = 0; i < n; i++){
        fscanf(fp, "%d ", &arr[i]);    
    }
    
    struct timeval start, end;
    double mtime, seconds, useconds;

    gettimeofday(&start, NULL);
    simple_sort(arr, n);
    printout(arr, n, output_file_name);
    gettimeofday(&end, NULL);
    seconds  = end.tv_sec  - start.tv_sec;
    useconds = end.tv_usec - start.tv_usec;
    mtime = ((seconds) * 1000 + useconds/1000.0) + 0.5;
    printf("simple_sort\n");
    printf("比較回数 : %d, 入れ替える回数：%d\n", compare_count, change_count);
    printf("処理時間 : %lfmillisecond\n", mtime);
    fclose(fp);
    
}

void simple_sort(int d[], int n){
    int temp;
    
    for(int i = 0; i < n-1; i++){//to find max score n times
        int max_data = d[i];//initialize max_number by putting each first index in max_number
        int max_number = i;//max_number initialization
        for(int j = i+1; j < n; j++){//to find max score and max score number
            if(d[j] > max_data){
                max_data = d[j];
                max_number = j;
            }
            compare_count++;
        }
        temp = d[i];//change index struct to max_number struct
        d[i] = d[max_number];
        d[max_number] = temp;
        change_count++;
    }
}

void bubble_count_time(char *input_file_name, char *output_file_name, int n){
    compare_count = 0;
    change_count = 0;
    int arr[n];
    FILE *fp = fopen(input_file_name, "r");
    for(int i = 0; i < n; i++){
        fscanf(fp, "%d ", &arr[i]);    
    }
    
    struct timeval start, end;
    double mtime, seconds, useconds;

    gettimeofday(&start, NULL);
    bubble_sort(arr, n);
    printout(arr, n, output_file_name);
    gettimeofday(&end, NULL);
    seconds  = end.tv_sec  - start.tv_sec;
    useconds = end.tv_usec - start.tv_usec;
    mtime = ((seconds) * 1000 + useconds/1000.0) + 0.5;
    printf("bubble_sort\n");
    printf("比較回数 : %d, 入れ替える回数：%d\n", compare_count, change_count);
    printf("処理時間 : %lfmillisecond\n", mtime);
    fclose(fp);
    
}

void bubble_sort(int d[], int n){
    int temp;
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-i-1; j++){
            compare_count++;
            if(d[j] < d[j+1]){
                temp = d[j];
                d[j] = d[j+1];
                d[j+1] = temp;
                change_count++;
            }
        }
    }
}

void quick_count_time(char *input_file_name, char *output_file_name, int n){
    compare_count = 0;
    change_count = 0;
    int arr[n];
    FILE *fp = fopen(input_file_name, "r");
    for(int i = 0; i < n; i++){
        fscanf(fp, "%d ", &arr[i]);    
    }
    
    struct timeval start, end;
    double mtime, seconds, useconds;

    gettimeofday(&start, NULL);
    quick_sort(arr, 0, n-1);
    printout(arr, n, output_file_name);
    gettimeofday(&end, NULL);
    seconds  = end.tv_sec  - start.tv_sec;
    useconds = end.tv_usec - start.tv_usec;
    mtime = ((seconds) * 1000 + useconds/1000.0) + 0.5;
    printf("quick_sort\n");
    printf("比較回数 : %d, 入れ替える回数：%d\n", compare_count, change_count);
    printf("処理時間 : %lfmillisecond\n", mtime);
    fclose(fp);
    
}

void quick_sort(int d[], int left, int right){
    int l = left, r = right;
    int pivot = d[(left + right) / 2]; // set up center index to pivot
    int temp; // temp variable to replace each element

    while (l <= r) {
        while (d[l] > pivot) {
            l++;
            compare_count++;
        }
        while (d[r] < pivot) {
            r--;
            compare_count++;
        }
        if (l <= r) {
            temp = d[l];
            d[l] = d[r];
            d[r] = temp;
            l++;
            r--;
            change_count++;
        }
    }

    if (left < r) {
        quick_sort(d, left, r); // new range left ~ r
    }
    if (l < right) {
        quick_sort(d, l, right); // new range l ~ right
    }
}

void merge_count_time(char *input_file_name, char *output_file_name, int n){
    compare_count = 0;
    change_count = 0;
    int arr[n];
    FILE *fp = fopen(input_file_name, "r");
    for(int i = 0; i < n; i++){
        fscanf(fp, "%d ", &arr[i]);    
    }
    
    struct timeval start, end;
    double mtime, seconds, useconds;

    gettimeofday(&start, NULL);
    merge_sort(arr, 0, n-1);
    printout(arr, n, output_file_name);
    gettimeofday(&end, NULL);
    seconds  = end.tv_sec  - start.tv_sec;
    useconds = end.tv_usec - start.tv_usec;
    mtime = ((seconds) * 1000 + useconds/1000.0) + 0.5;
    printf("merge_sort\n");
    printf("比較回数 : %d, 入れ替える回数：%d\n", compare_count, change_count);
    printf("処理時間 : %lfmillisecond\n", mtime);
    fclose(fp);
    
}

void merge_sort(int d[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        merge_sort(d, left, mid);
        merge_sort(d, mid + 1, right);
        merge(d, left, mid, right);
    }
}

void merge(int d[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = d[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = d[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        compare_count++;
        if (L[i] >= R[j]) {
            d[k] = L[i];
            i++;
        } else {
            d[k] = R[j];
            j++;
        }
        k++;
        change_count++;
    }

    while (i < n1) {
        d[k] = L[i];
        i++;
        k++;
        change_count++;
    }

    while (j < n2) {
        d[k] = R[j];
        j++;
        k++;
        change_count++;
    }
}
