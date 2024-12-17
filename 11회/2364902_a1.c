#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPR_LEN 100

void print_expr(int expr[], char ops[], int len);
int calculation(int expr[], char ops[], int len);
void make_expr(int n, int expr[], char ops[], int len);
void komachi_solver();

int main() {
    komachi_solver();
    return 0;
}


void print_expr(int expr[], char ops[], int len) {
    for (int i = 0; i < len; i++) {
        if (i > 0) {
            printf(" %c ", ops[i - 1]);
        }
        printf("%d", expr[i]);
    }
    printf(" = 100\n");
}

int calculation(int expr[], char ops[], int len) {
    int result = expr[0];
    for (int i = 1; i < len; i++) {
        if (ops[i - 1] == '+') {
            result += expr[i];
        } else {
            result -= expr[i];
        }
    }
    return result;
}

void make_expr(int n, int expr[], char ops[], int len) {
    if (n == 10) {
        if (calculation(expr, ops, len) == 100) {
            print_expr(expr, ops, len);
        }
        return;
    }

    // add + 
    ops[len - 1] = '+';//add + operation into ops
    expr[len] = n;//add number into expr
    make_expr(n + 1, expr, ops, len + 1);//recursion

    // add -
    ops[len - 1] = '-';
    expr[len] = n;
    make_expr(n + 1, expr, ops, len + 1);

    // connect two number
    int last_num = expr[len - 1];
    if (last_num >= 0) {//when first number is +1
        expr[len - 1] = last_num * 10 + n;
        make_expr(n + 1, expr, ops, len);
        expr[len - 1] = last_num; // restore
    } else {
        expr[len] = n; // when first number is -1
        make_expr(n + 1, expr, ops, len + 1);
        expr[len] = last_num; // restore
    }
}

void komachi_solver() {
    
    //when first number is +1
    int expr[MAX_EXPR_LEN] = {1};
    char ops[MAX_EXPR_LEN - 1] = {0};
    make_expr(2, expr, ops, 1);
    
    //when first number is -1
    int expr1[MAX_EXPR_LEN] = {-1};
    char ops1[MAX_EXPR_LEN - 1] = {0};
    make_expr(2, expr1, ops1, 1);
}

