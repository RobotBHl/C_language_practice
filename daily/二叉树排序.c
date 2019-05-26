#include<stdio.h>
#include<stdlib.h>
#include"tree.h"

int main(void) {
    int node_num, i = 0, temp;
    Node *root = NULL;
    scanf("%d", &node_num);
    while (i < node_num) {
        scanf("%d", &temp);
        if (i == 0) root = init_root(temp);
        else insert_node(root, temp);
        i++;
    }
    traverse_tree_inorder(root);
    printf("\n");
    recycle_nodes(root);
    return 0;
}

 /*tree.h*/
 # include <stdlib.h>
# include <stdio.h>
typedef struct Node {
    struct Node *left;
    struct Node *right;
    int value;
} Node;
Node* init_root(int value) {
    Node *root;
    root = malloc(sizeof(Node));
    root->value = value;
    root->left = NULL;
    root->right = NULL;
    return root;
}
void insert_node(Node *p, int value) {
    Node *pArr;
    pArr = malloc(sizeof(Node));
    pArr->value = value;
    pArr->left = NULL;
    pArr->right = NULL;
    while (p->left != pArr && p->right != pArr) {
        while (value > p->value) {
            if (p->right == NULL) {
                p->right = pArr;
                return;
            } else {
                p = p->right;
            }
        }
        while (value < p->value) {
            if (p->left == NULL) {
                p->left = pArr;
                return;
            } else {
                p = p->left;
            }
        }
    }
    return;
}
void traverse_tree_inorder(Node *p) {
    if (p == NULL)
        return;
    traverse_tree_inorder(p->left);
    printf("%d ", p->value);
    traverse_tree_inorder(p->right);
}
void recycle_nodes(Node *p) {
    if (p == NULL)
        return;
    recycle_nodes(p->left);
    recycle_nodes(p->right);
    free(p);
}
