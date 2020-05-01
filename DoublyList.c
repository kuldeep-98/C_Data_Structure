#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
}*first = NULL;

void Create(int A[],int n){
    struct Node *t,*last;
    int i;

    first = (struct Node*)malloc(sizeof(struct Node));
    first->prev=NULL;
    first->data = A[0];
    first->next = NULL;
    last = first;
    for (int i = 1; i < n; ++i) {
        t = (struct Node*)malloc(sizeof(struct Node));
        t->prev = last;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void insert(struct Node *p,int index,int value){
    struct Node *t = (struct Node*)malloc(sizeof(struct Node));
    t->data = value;
    if (index == 0){
        t->prev = p->prev;
        t->next = p;
        first = t;
    } else{
        for (int i = 0; i <index-1 ; ++i) {
            p = p->next;
        }
        t->next = p->next;
        t->prev = p;
        p->next = t;
    }
}

void Display(struct Node *p){
    while (p!=NULL){
        printf("%d->",p->data);
        p = p->next;
   //     if (p->next==NULL) break;
    }
//    while (p!=NULL){
//        printf("%d->",p->data);
//        p = p->prev;
//    }
printf("\n");
}

void Delete(struct Node *p,int value){
    if (p->data==value){
        first = p->next;
        if (first) first->prev = NULL;
    } else{
        while (p){
            if(p->data == value) break;
            else p = p->next;
        }
        if(p==NULL)
            return;
        p->prev->next = p->next;
        p->next = p->prev;
    }
}

void Reverse(struct Node *p){
    struct Node *t;
    while (p->next!=NULL){
        t = p->next;
        p->next = p->prev;
        p->prev = t;
        p = p->prev;
       // if (p!=NULL&& p->next==NULL)first = p;
    }
    p->next = p->prev;
    p->prev =NULL;
    first = p;
}

int main(){
    int A[] = {2,4,5,7,8,9};
    Create(A,6);
    Display(first);
    insert(first,6,10);
    Display(first);
    Delete(first,11);
    Display(first);
    Reverse(first);
    Display(first);
    return 0;
}