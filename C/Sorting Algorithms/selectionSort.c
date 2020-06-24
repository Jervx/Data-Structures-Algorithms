#include <stdio.h>

void printArray(int * arr, int n){
    int x = 0;
    printf("Array -> [");
    for(; x < n; x++) printf("%d%s",arr[x],x == n-1? "":", ");
    printf("]\n");
}

void selectionSort(int * arr,int n){
    int x, y;
    int key = 0;
    for(x = 0; x < n; x++){
        for(y =x + 1; y < n; y++)
            if(arr[key] > arr[y]) key = y;
        int temp = arr[x];
        arr[x] = arr[key];
        arr[key] = temp;
        key = x+1;
    }
}

int main(){
    int arr[] = {1,2,6,18,15};
    int n = sizeof(arr) / sizeof(int);
    printArray(arr,n);
    selectionSort(arr,n);
    printArray(arr,n);
}