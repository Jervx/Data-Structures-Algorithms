#include <stdio.h>
#include <stdlib.h>

void printArr(int arr[], int n){
    int x = 0;
    printf("Array -> [");
    for(; x < n; x++) printf("%d%s",arr[x],x+1 == n? "":", ");
    printf("]\n");
}

void swap(int * n1, int * n2){
    int t = *n1;
    *n1 = *n2;
    *n2 = t;
}

int part(int ar[], int l, int r){
    int pvt = ar[r], y = l - 1, tmp;
    for(int x = l ; x < r; x++)
        if(ar[x]<= pvt) swap(&ar[x],&ar[++y]);
    swap(&ar[++y],&ar[r]);
    return y;
}

void quickSort(int ar[], int l , int r){
    if(l >= r) return;
    int mid = part(ar, l, r);
    quickSort(ar,l, mid - 1);
    quickSort(ar, mid + 1, r);
}

int main(){
    int arr[] = {6,1,3,7,5,4,8}, n = sizeof(arr)/sizeof(int);
    printArr(arr,n);
    quickSort(arr,0,n-1);
    printArr(arr,n);
}