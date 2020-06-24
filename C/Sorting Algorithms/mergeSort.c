#include <stdio.h>
#include <stdlib.h>

void printArray(int arr[], int n){
    int x = 0;
    printf("Array -> [");
    for(; x < n; x++) printf("%d%s",arr[x],x == n-1? "":", ");
    printf("]\n");
}

int getSize(int * arr){return sizeof(arr)/sizeof(int);}

void merge(int * arr, int p, int q, int r) {

    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1], M[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];

    printf("\n-----------------------------\nL : -> ");
    printArray(L,getSize(L));

    for (int j = 0; j < n2; j++)
        M[j] = arr[q + 1 + j];

    printf("\nM : -> ");
    printArray(M,getSize(M));

    int i, j, k;
    i = 0;
    j = 0;
    k = p;

    while (i < n1 && j < n2) {
        if (L[i] <= M[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = M[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = M[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
  if (l < r) {
    int m = l + (r - l) / 2; 

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    merge(arr, l, m, r);
  }
}

int main(){
    int ar[] = {5,8,19,3,1};
    int n = sizeof(ar)/sizeof(int);

    mergeSort(ar,0,n-1);
    printArray(ar,n);
}