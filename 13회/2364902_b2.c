#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct list{
    int num;//number
    char name[20];//name
    char profile[60];//position, date of birth, height, weight, team
    struct list *next; 
};

struct list *get_list(FILE *);//function to get list
void print_list(struct list *p);//function to print list
struct list *deleteList(struct list *p, int inputNum);
void free_list(struct list *p);

int main(int argc, char*argv[]){
    FILE *fp = fopen(argv[1], "r");//open file read type
    struct list *listptr;//list to get list and print list
    struct list *deletelist;
    int input_Num = 0;
    
    if(fp == NULL){//when program fail to open file
        fprintf(stderr, "file is not open\n");
        return 1;
    }
    
    else{
        listptr = get_list(fp);//get list
        print_list(listptr);//print list
    }

    while(1){
        printf("登録番号は？");
        scanf("%d", &input_Num);
        
        if(input_Num == 0){
            break;
        }
        else{
            deletelist = deleteList(listptr, input_Num);//save the struct input number
    
            if(deletelist == NULL){//when searchLIst return NULL
                printf(" ---該当者はいません---\n");
            }
            else{
                print_list(deletelist);
                listptr = deletelist;//update list to input list to deleteList function
            }
        }
    }
    fclose(fp);//close file
    
    free_list(listptr);//free all list
    
    return 0;
}

struct list *get_list(FILE *fp){
    struct list *temp, *new_temp;
    struct list data;
    temp = NULL;
    for(;(fscanf(fp, "%d %s %s", &data.num, data.name, data.profile)) != EOF;){
        new_temp = (struct list*)malloc(sizeof(struct list));//free up memory
        new_temp->num = data.num;//input data num to new temp num
        strcpy(new_temp->name, data.name);//copy data name to new temp name
        strcpy(new_temp->profile, data.profile);//copy data profile to new temp profile
        new_temp->next = temp; temp=new_temp;//connect new temp with temp
    }
    return temp;//return list
}

void print_list(struct list *p){
    for(;p != NULL; p = p->next){
        printf("%2d %s %s\n", p->num, p->name, p->profile);
    }
    printf("\n");
}

struct list *deleteList(struct list *p, int inputNum) {
    struct list *previous = NULL;

    for(struct list *current = p; current != NULL; current = current->next) {
        if (current->num == inputNum) {
            if (previous != NULL) {
                previous->next = current->next;//connect previous list to next list
                printf("---削除しました---\n");
                return p;
            } 
            else {//when input number is first number
                printf("---削除しました---\n");
                return p->next;//return second list
            }
        }
        previous = current;
        
    }
    return NULL;
}

void free_list(struct list *p) {//free all list
    struct list *temp;
    while (p != NULL) {
        temp = p;
        p = p->next;
        free(temp);
    }
}