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
tree_mbr *search_and_delete(tree_mbr *root, int num);//search and delete func

int main(int argc, char *argv[]){
    FILE* fp = fopen(argv[1], "r");
    if(fp == NULL){
        printf("Error opening file!\n");
        return 1;
    } 
    
    tree_mbr *root = NULL;
    tree_mbr data;

    for(;fscanf(fp, "%d %20s %60s", &data.num, data.name, data.profile) != EOF;){// scanf data and input struct data
        root = tree(data, root);//input tree
    }

    fclose(fp);

    int option;
    int num;

    while(1) {
        printf("1: 探索 2: 削除 3: 表示 4: 終了\n");
        scanf("%d", &option);

        switch(option) {
            case 1:
                printf("検索する登録番号を入力してください: ");
                scanf("%d", &num);
                search_and_delete(root, num);
                break;
            case 2:
                printf("削除する登録番号を入力してください: ");
                scanf("%d", &num);
                root = search_and_delete(root, num);
                break;
            case 3:
                inorder(root, 0);
                break;
            case 4:
                return 0;
            default:
                printf("無効な選択です。もう一度お試しください。\n");
        }
    }

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

tree_mbr *search_and_delete(tree_mbr *root, int num) {
    if(root == NULL) {//when root is NULL(tree is blank)
        printf("登録番号 %d は見つかりませんでした。\n", num);
        return root;//return root(NULL)
    }

    if(num < root->num) {//if num is smaller than current num
        root->left = search_and_delete(root->left, num);//search left side
    } else if(num > root->num) {//if num is bigger than current num
        root->right = search_and_delete(root->right, num);//search right side
    } else {//when num is current num(search success)
        printf("登録番号 %d: %s %s\n", root->num, root->name, root->profile);

        if(root->left == NULL) {//when left child is NULL
            tree_mbr *temp = root->right;
            free(root);
            return temp;
        } else if(root->right == NULL) {//when right child is NULL
            tree_mbr *temp = root->left;
            free(root);
            return temp;
        }
        
        //when parent have right child and left chile, search minimum value in left side 
        tree_mbr *temp = root->right;
        while(temp && temp->left != NULL) {
            temp = temp->left;
        }
        
        // replace the current node with the minimum value
        root->num = temp->num;
        strcpy(root->name, temp->name);
        strcpy(root->profile, temp->profile);
        
        //delete minimum value node in right side
        root->right = search_and_delete(root->right, temp->num);
    }
    return root;
}
