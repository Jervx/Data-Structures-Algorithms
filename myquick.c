#include <stdio.h>
#include <stdlib.h>

void printArr(int ar[], int n){
    printf("[");
    for(int x = 0; x < n; x++)printf("%d%s",ar[x],x != n-1?",":"]\n");
}

void swap(int * n1, int * n2){
    int tep = * n1;
    * n1 = * n2;
    * n2 = tep;
}

int partition(int ar[], int l, int r){
    int pvt = ar[r],y = l - 1;
    for(int x = l; x < r; x++)
        if(ar[x] <= pvt) swap(&ar[x],&ar[++y]);
    swap(&ar[++y],&ar[r],ar[y]);
    return y;
}

void quickSothu(int ar[], int l, int r){
    if(l >= r) return;
    int mid = partition(ar, l , r);
    quickSothu(ar,l,mid - 1);
    quickSothu(ar,mid+1,r);
}

int main(){
    int ar[] = {33,1,7,19,20,4}, n = sizeof(ar)/sizeof(int);
    printArr(ar,n);
    quickSothu(ar,0,n-1);
    printArr(ar,n);
}