#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node *left;
    int data;
    struct Node *right;
} *root = NULL;

void Insert(struct Node *p, int value) {
    struct Node *t;
    struct Node *r;
    if (root == NULL) {
        t = (struct Node *) malloc(sizeof(struct Node));
        t->data = value;
        t->left = NULL;
        t->right = NULL;
        root = t;
        return;
    }
    while (p != NULL) {
        r = p;
        if (p->data < value) {
            p = p->right;
        } else if (p->data>value){
            p = p->left;
        } else return;
    }
    t = (struct Node *) malloc(sizeof(struct Node));
    t->data = value;
    t->left =  t->right  = NULL;
    if (value<r->data) r->left = t;
    else r->right = t;
}

void InOrder(struct Node *p){
    if (p!=NULL){
        InOrder(p->left);
        printf("%d \t",p->data);
        InOrder(p->right);
    }
}

int main() {
    Insert(root,10);
    Insert(root,5);
    Insert(root,8);
    Insert(root,12);
    Insert(root,16);
    Insert(root,2);
    InOrder(root);

    return 0;
}
