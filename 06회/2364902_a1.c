#include <stdio.h>
#include <string.h>
#define EOS '\0'
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int Longest_common_subsequence(char s[], char t[], char s_s[]);

int main(void){
    char str_s[100];
    char str_t[100];
    char same_str[100];
    
    printf("文字列 s = ");
    gets(str_s);
    printf("文字列 t = ");
    gets(str_t);
    
    int len = Longest_common_subsequence(str_s, str_t, same_str);
    
    printf("文字列 s, t の共通部分列は \" %s \" であり、共通部分列の長さは%dです。", same_str, len);
    
    return 0;
}


int Longest_common_subsequence(char s[], char t[], char s_s[]){
    int len_s = strlen(s);
    int len_t = strlen(t);
    int i, j, index = 0;
    int double_matrix[len_s+1][len_t+1];//動的割り当てのテーブル配列を宣言
    
    for(i=0; i<=len_s; i++){//動的割り当てのテーブルを構築
        for(j=0; j<=len_t; j++){
            if(i == 0 || j == 0){//インデックス０を０に設定
                double_matrix[i][j] = 0;
            }
            else if(s[i-1] == t[j-1]){//文字が同じ場合
                double_matrix[i][j] = double_matrix[i-1][j-1] + 1;//以前の対角線値に1を足す
            }
            else{//文字が違う場合
                double_matrix[i][j] = MAX(double_matrix[i-1][j], double_matrix[i][j-1]);//以前の最大共通数を維持する。
            }
        }
    }
    
    //最大の文字列を保存するための操作（バックトラッキング）
    i = len_s, j = len_t;//最大文字数が入っているテーブルの位置から始まる
    for(;i > 0 && j > 0;){
        if(s[i-1] == t[j-1]){//文字が同じ場合
            s_s[index++] = s[i-1];//same_strに保存
            i--; j--;
        }
        else if(double_matrix[i-1][j] > double_matrix[i][j-1]){//最大文字列の一部ではないとき
            i--;
        }
        else{//最大文字列の一部ではないとき
            j--;
        }
    }
    s_s[index] = EOS;//文字の最後を確認するEOSを入れる。
    for(i = 0; i < index / 2; i++){//文字列が逆順なので元の順序に変える
        char temp = s_s[i];
        s_s[i] = s_s[index-i-1];
        s_s[index-i-1] = temp;
    }
    return double_matrix[len_s][len_t];
}