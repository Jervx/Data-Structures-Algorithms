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
    int n1 = q - p + 1, n2 = r - q, L[n1], M[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[p + i];
    for (int j = 0; j < n2; j++) M[j] = arr[q + 1 + j];

    int i = 0, j = 0, k = p;

    while (i < n1 && j < n2) 
        if (L[i] <= M[j]) 
            arr[k++] = L[i++];
        else 
            arr[k++] = M[j++];

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = M[j++];
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
    int ar[] = {5, 1, 6, 22, 14, 8, 3, 7, 21, 9};
    int n = sizeof(ar)/sizeof(int);
    int x = 0;
    printf("\n%d\n",ar[x++]);
    printArray(ar,n);
    mergeSort(ar,0,n-1);
    printArray(ar,n);
}