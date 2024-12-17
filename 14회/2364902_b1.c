#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct member {
    int num; 
    char name[21];
    char profile[61];
    struct member *left;
    struct member *right;
};


typedef struct member tree_mbr;// use tree_mbr to replace struct member 

tree_mbr *tree(tree_mbr data, tree_mbr *root);//make tree
void inorder(tree_mbr *root, int height);//print tree

int main(int argc, char *argv[]){
    FILE* fp = fopen(argv[1], "r");
    if(fp == NULL){
        printf("Error to open file!\n");
        return 1;
    }
    
    tree_mbr *root = NULL;
    tree_mbr data;

    for(;fscanf(fp, "%d %20s %60s", &data.num, data.name, data.profile) != EOF;){// scanf data and input struct data
        root = tree(data, root);//input tree
    }

    fclose(fp);

    inorder(root, 0);//print tree

    return 0;
}

tree_mbr *tree(tree_mbr data, tree_mbr *root) {
    tree_mbr *new_node = (tree_mbr *)malloc(sizeof(tree_mbr));//allocation new node
    if(new_node == NULL) {
        printf("Error to allocate memory!\n");
        exit(1);
    }
    *new_node = data;//input data to new node
    new_node->left = NULL;//initialization left side
    new_node->right = NULL;//initialization right side

    if(root == NULL) {//when root is NULL make root by using new node
        return new_node;
    }
    
    tree_mbr *parent = NULL;//initialization parent node

    for(tree_mbr *current = root; current != NULL;) {   
        parent = current;//set parent node to current
        if(data.num < current->num) {//when data.num is smaller than current num
            current = current->left;//move left side
        } else {//when data.num is bigger than current num
            current = current->right;//move right side
        }
    }

    if(data.num < parent->num) {//set new node to left child or right child
        parent->left = new_node;
    } else {
        parent->right = new_node;
    }

    return root;
}

void inorder(tree_mbr *root, int height) {
    if(root == NULL) {//when root is blank or end of tree, return blank
        return;
    }

    inorder(root->right, height + 1);//recursive call(visit right side and height + 1)

    for(int i = 0; i < height; i++) {//make blank as height
        printf("    ");
    }
    printf("%d %s %s\n", root->num, root->name, root->profile);//print current root

    inorder(root->left, height + 1);//recursive call(visit left and height + 1)
}
