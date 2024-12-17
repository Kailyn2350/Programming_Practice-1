#include <stdio.h>

int main(int argc, char *argv[]){
    FILE* fp1 = fopen(argv[1], "r");//file1 open as reading type
    FILE* fp2 = fopen(argv[2], "w");//file2 oepn as writing type
    if(fp1 == NULL || fp2 == NULL){//when program can't open file
        printf("入力ファイルを開けませんでした\n");
        return 1;
    }
    
    char format[3];//save format data
    int width, height, max_val, pixel;
    
    fscanf(fp1, "%s", format);//first row data
    fscanf(fp1, "%d %d", &width, &height);//second row data
    fscanf(fp1, "%d", &max_val);//3rd row data
    
    fprintf(fp2, "%s\n", format);//input first row format data into file2
    fprintf(fp2, "%d %d\n", width, height);
    fprintf(fp2, "%d\n", max_val);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            fscanf(fp1, "%d", &pixel);
            if (pixel > max_val / 2) {//when pixel data value is less than one-half of max_val
                pixel = max_val;//input max_val to pixel
            } else {
                pixel = 0;
            }
            fprintf(fp2, "%d\n", pixel);//print pixel into file2
        }
    }
    
    fclose(fp1);
    fclose(fp2);
    
    printf("元ファイル名 = %s\n", argv[1]);
    printf("作成ファイル名 = %s\n", argv[2]);
    
    return 0;
}