#include <stdio.h>
#include <stdlib.h>

void inputArr(int *arr, int count, int m, int n);
int num=-1;//val to calculate array number - 1
int data[100][9];

int main(int argc, char *argv[])
{
    int m, n;
    FILE *fp;
    
    printf("1桁の正数 M を入力してください\n");
    printf("M = "); scanf("%d", &m);
    printf("1桁の正数 N を入力してください\n");
    printf("N = "); scanf("%d", &n);
    
    int arr[n];
    
    if((fp = fopen(argv[1], "w")) == NULL){
        fprintf(stderr, "%s is not open\n", argv[1]);
        exit(1);
    }
    
    printf("1から%dまでの数字を%d個並べた処理結果をファイル%sに出力します\n", m, n, argv[1]);
    
    inputArr(arr, 0, m, n);
    
    int c;
    int l, j, i, a;
    int n_line = 78/(2*n+1); //the number of sets in a page 
    int group;  //the number of 20 sets
    
    if((num+1) % 20 == 0) group = (num+1)/20;
    else group = (num+1)/20 + 1;
    
    //print into file
    for(l=0; l<20; l++){
        c=0;
        for(j=l; j<=num; j+=20){
            c++;
            if(c > n_line){
                j-=20;
                break;
            }
            for(i=0; i<n; i++){
                fprintf(fp, "%d ", data[j][i]);
            }
            fprintf(fp, " ");
        }
        fprintf(fp, "\n");
    }
        //When the number of sets is greater than the number of sets 1st page
    if(group > n_line){
        fprintf(fp, "\n");
        for(l=0; l<20+j; l++){
            for(i=l+j; i<=num; i+=20){
                for(a=0; a<n; a++){
                    fprintf(fp, "%d ", data[i][a]);
                }
                fprintf(fp, " ");
            }
            fprintf(fp, "\n");
        }
    }

    fclose(fp);
    
    return 0;
}

void inputArr(int *arr, int count, int m, int n)
{
    int i;
    
    if(count == n){
        num++;
        for(i=0; i<n; i++){
            data[num][i] = arr[i];
        }
    }else{
        for(i=1; i<=m; i++){
            arr[count] = i;
            inputArr(arr, count+1, m, n);
        }
    }
}