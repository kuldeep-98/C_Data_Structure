#include <stdio.h>

void Insert(int h[], int n){
    int i = n,temp;
    temp = h[i];
    while (i>1 && temp>h[i/2])
    {
        h[i] = h[i/2];
        i=i/2;
    }
    h[i] = temp;
}

int Delete(int h[], int n){
    int i,j,x,temp, val;
    x = h[n];
    val = h[1];
    h[1] = x;
    h[n]=val;
    i=1, j=i*2;
    while (j<n-1)
    {
        if(h[j+1]>h[j])
            j=j+1;
        if (h[j]>h[i])
        {
            temp = h[i];
            h[i]=h[j];
            h[j]=temp;
            i=j;
            j=2*i;
        }else
        {
            break;
        }
    }
    return val;
}

int main(){
    int h[] = {0,10,20,30,25,5,40,35,70};

    for(int i=2;i<=8;i++){
        Insert(h,i);
    }
    //printf("Delete %d",Delete(h,8));
    for (int i = 8; i > 0; i--)
    {
        Delete(h,i);
    }
    
    for (int i = 1; i <=8; i++)
    {
        printf("%d\t",h[i]);
    }
}