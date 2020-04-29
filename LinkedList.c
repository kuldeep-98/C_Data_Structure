#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

struct List {
    int data;
    struct List *next;
} *head = NULL,*end = NULL,*sec=NULL,*third=NULL;

void Create(int A[], int n) {
    int i;
    struct List *t, *last;
    head = (struct List *) malloc(sizeof(struct List));
    head->data = A[0];
    head->next = NULL;
    last = head;
    for (i = 1; i < n; i++) {
        t = (struct List *) malloc(sizeof(struct List));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}
void Create2(int A[], int n) {
    int i;
    struct List *t, *last;
    sec = (struct List *) malloc(sizeof(struct List));
    sec->data = A[0];
    sec->next = NULL;
    last = sec;
    for (i = 1; i < n; i++) {
        t = (struct List *) malloc(sizeof(struct List));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void Display(struct List *p) {
    while (p != NULL) {
        printf("%d->", p->data);
        p = p->next;
    }
    printf("\n");
}

void RDisplay(struct List *p) {
    if (p == NULL)return;
    else {
        RDisplay(p->next);
        printf("%d->", p->data);
    }
    printf("\n");
}

int Count(struct List *p) {
    if (!p) return 0;
    else
        return Count(p->next) + 1;
}

int Add(struct List *p){
    if (!p) return 0;
    else return Add(p->next) + p->data;
}

int Max(struct List *p){
    int max = INT32_MIN;
    while (p){
        if (p->data >max)
            max = p->data;
        p = p->next;
    }
    return max;
}

int Search(struct List *p,int key){
    int pos = 0;
    while (p!=NULL){
        if(p->data==key)
            return pos+1;
        p = p->next;
        pos++;
    }
    return -1;
}

void insert(struct List *p,int index, int value){
    struct List *n = (struct List *)malloc(sizeof(struct List));
    n->data = value;
    if (index == 0){
        n->next = head;
        head = n;
    } else {
        for (int i = 0; i < index-1; ++i) {
            p = p->next;
        }
        n->next = p->next;
        p->next = n;
    }
}

void insertLast(struct List *p,int value){
    struct List *n = (struct List *)malloc(sizeof(struct List));
    n->data = value;
    n->next = NULL;
    if (head == NULL){
        head = end = n;
    } else{
        end->next = n;
        end = n;
    }
}

void insertSorted(struct List *p, int value){
    struct List *n = (struct List*)malloc(sizeof(struct List));
    n->data = value;
    n->next = NULL;
    if(head == NULL){
        head = n;
    }
    else if (p->data>value){
        n->next = p;
        head = n;
    } else {
        struct List *prev;
        while(p) {
            if (p->data < value) {
                prev = p;
                p = p->next;
            } else break;
        }
        prev->next = n;
        n->next = p;
    }
}

void Delete(struct List *p,int key){
    if(p->data==key){
        head = p->next;
        free(p);
    } else{
        struct List *prev;
        while (p){
            if (p->data==key) break;
            else{
                prev = p;
                p = p->next;
            }
        }
        prev->next = p->next;
        free(p);
    }
}

int isSorted(struct List *p){
    struct List *prev;
    while (p->next!=NULL){
        prev = p;
        p = p->next;
        if (prev->data>p->data) return  0;
    }
    return 1;
}

void removeSortDuplicate(struct List *p){
    struct List *prev;
    while (p->next!=NULL){
        prev = p;
        p = p->next;
        if (prev->data==p->data){
            prev->next = p->next;
            p = prev;
        }
    }
}

void RReverse(struct List *p,struct List *prev){
    if (p==NULL){
      head = prev;
    }
    else{
        RReverse(p->next,p);
        p->next = prev;
    }
}

void Reverse(struct List *p){
    struct List *q = NULL;
    struct List *r = NULL;
    while (p!=NULL) {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    head = q;
}

void Concat(struct List* f, struct List *s){
    while (f->next!=NULL){
        f = f->next;
    }
    f->next = s;
}

void Merge(struct List *f,struct List *s){
    struct List *last;
    if(f->data<s->data){
        third=last=f;
        f = f->next;
        last->next = NULL;
    } else{
        third = last = s;
        s = s->next;
        last->next =NULL;
    }
    while (f!=NULL&&s!=NULL){
        if (f->data<s->data){
            last->next = f;
            last = f;
            f = f->next;
            last->next=NULL;
        } else{
            last->next = s;
            last = s;
            s = s->next;
            last->next=NULL;
        }
    }
    if (f!=NULL) last->next = f;
    if (s!=NULL) last->next = s;
}

int main() {
    int A[] = {3, 5, 6, 8, 9};
    int B[] = {2, 4, 7, 10};
    Create(A, 5);
    Create2(B,4);
    Display(head);
    Display(sec);
    Merge(head,sec);
    Display(third);
   // Concat(head,sec);
   // Display(head);
    //Display(head);
    //RDisplay(head);
    //insert(head,1,10);
    //Display(head);
   // insert(head,0,8);
   // insert(head,1,9);
    //insertLast(head,10);
//    insertLast(head,13);
//    insertLast(head,15);
//    insertSorted(head,9);
//    insertSorted(head,18);
//    insertSorted(head,18);
//    insertSorted(head,15);
//    insert(head,5,18);
//    Display(head);
//    Delete(head,9);
//    Display(head);
//    if (isSorted(head)) printf("Sorted\n");
//    else printf("not sorted");
//    removeSortDuplicate(head);
//    Display(head);
//    RReverse(head,NULL);
//    Display(head);
//    Reverse(head);
//    Display(head);
//    printf("%d\n",Count(head));
//    printf("%d\n",Add(head));
//    printf("%d\n",Max(head));
//    printf("%d\n",Search(head,9));

    return 0;
}
