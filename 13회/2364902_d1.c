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
struct list* sortList(struct list *list);
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
        listptr = sortList(listptr);//sort list
        print_list(listptr);//print list
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

struct list* sortList(struct list *head) {
    if (head == NULL || head->next == NULL) {
        return head; // if list is empty or has only one element, return it as is
    }

    struct list *i, *j;
    int swapped;

    for (i = head; i != NULL; i = i->next) {
        swapped = 0;

        for (j = head; j->next != NULL; j = j->next) {
            if (j->num > j->next->num) {
                // swap the contents of the nodes
                int temp_num = j->num;
                char temp_name[20], temp_profile[60];

                strcpy(temp_name, j->name);
                strcpy(temp_profile, j->profile);

                j->num = j->next->num;
                strcpy(j->name, j->next->name);
                strcpy(j->profile, j->next->profile);

                j->next->num = temp_num;
                strcpy(j->next->name, temp_name);
                strcpy(j->next->profile, temp_profile);

                swapped = 1;
            }
        }

        if (!swapped) {
            break; // exit the loop if no swapping occurred in the inner loop
        }
    }

    return head;
}


void free_list(struct list *p) {//free all list
    struct list *temp;
    while (p != NULL) {
        temp = p;
        p = p->next;
        free(temp);
    }
}