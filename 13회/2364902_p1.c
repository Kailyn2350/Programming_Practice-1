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

int main(int argc, char*argv[])
{
    FILE *fp = fopen(argv[1], "r");//open file read type
    struct list *listptr;//list to get list and print list
    
    if(fp == NULL){//when program fail to open file
        fprintf(stderr, "file is not open\n");
        return 1;
    }else{
        listptr = get_list(fp);//get list
        print_list(listptr);//print list
    }
    
    fclose(fp);//close file
    
    return 0;
}

struct list *get_list(FILE *fp)
{
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

void print_list(struct list *p)
{
    for(;p != NULL; p = p->next){
        printf("%2d %s %s\n", p->num, p->name, p->profile);
    }
    printf("\n");
}