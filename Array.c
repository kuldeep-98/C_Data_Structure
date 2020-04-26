#include <stdio.h>
#include <stdlib.h>
struct Array {
    int A[10];
    int size;
    int length;
};

void append(struct Array *arr, int value) {
    if (arr->length < arr->size)
        arr->A[arr->length++] = value;
}

void insert(struct Array *a, int index, int value) {
    for (int i = a->length; i > index; i--) {
        a->A[i] = a->A[i - 1];
    }
    a->A[index] = value;
    a->length++;
}

void delete(struct Array *a, int index){
    int x = a->A[index];
    for (int i = index; i <a->length ; ++i) {
        a->A[i] = a->A[i+1];
    }
    a->length--;
    printf("%d is deleted",x);
}

int linearSearch(struct Array a, int value) {
    int i = 0;
    for (i = 0; i <a.length;i++){
        if (a.A[i]==value) return i;
    }
    return -1;
}

int binarySearch(struct Array a, int value){
    int low = 0, high = a.length-1 , mid ;
    while (low<=high){
        mid = (low + high)/2;
        if (a.A[mid]==value) return mid;
        else if (a.A[mid]>value) high = mid-1;
        else low = mid+1;
    }
    return -1;
}

void display(struct Array *a) {
    for (int i = 0; i < (*a).length; ++i) {
        printf("%d\t", (*a).A[i]);
    }
    printf("\n");
}

void reverse (struct Array *a) {
    int temp;
    for (int i = 0,j=a->length-1; i < j ; ++i,j--) {
        temp = a->A[i];
        a->A[i] = a->A[j];
        a->A[j] = temp;
    }
}

void insertSorted (struct Array *a , int value){
    int i ;
    for ( i = a->length-1; a->A[i] >value ; i--) {
        if (a->A[i]>value) a->A[i+1] = a->A[i];
    }
    a->A[i+1] = value;
    a->length++;
}

int isSorted(struct Array a){
    for (int i = 0; i <a.length-1 ; ++i) {
        if (a.A[i+1]<a.A[i]) return -1;
    }
    return 0;
}

struct Array* merge(struct Array a,struct Array b){
    int k=0;
    int i=0,j=0;
    struct Array *c = (struct Array *)malloc(sizeof(struct Array));
    while (i<a.length&&j<b.length){
        if (a.A[i]>b.A[j]){
            c->A[k++] = b.A[j++];
        } else c->A[k++] = a.A[i++];
    }
    while (i<a.length){
        c->A[k++] = a.A[i++];
    }
    while (j<b.length){
        c->A[k++] = b.A[j++];
    }
    c->length = a.length+b.length;
    return c;
}

int main() {
    struct Array array = {{2, 3, 6, 8, 9}, 10, 5};
    struct Array b =  {{4,5,7,10},10,4};
    struct Array *a = &array;
    //append(a, 10);
    //insert(a, 4, 15);
    //display(a);
    //delete(a,4);
    //insertSorted(a,10);
    display(a);
    display(&b);
    display(merge(array,b));
    if (isSorted(array)==0) printf("Array is sorted");
    else printf("not sorted");
//    reverse(a);
//    display(a);
}
