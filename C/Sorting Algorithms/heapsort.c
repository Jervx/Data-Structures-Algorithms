//JERBEE S. PARAGAS

#include <stdio.h>

void swap(int *n1, int *n2) {
    int temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

void printAr(int ar[],int n){
    printf("[");
    for(int x = 0; x < n; x++) printf("%d%s",ar[x],x != n-1?", ":"]\n");
}

void heapify(int ar[], int n, int i) {
    int l = i, lft = 2 * i + 1, rgt = 2 * i + 2;
    if (lft < n && ar[lft] > ar[l]) l = lft;
    if (rgt < n && ar[rgt] > ar[l]) l = rgt;
    if (l != i) {
        swap(&ar[i], &ar[l]);
        heapify(ar, n, l);
    }
}

void heapSort(int ar[], int n) {
    for (int x = n / 2 - 1; x >= 0; x--) heapify(ar, n, x);
    for (int x = n - 1; x >= 0; x--) {
        swap(&ar[0], &ar[x]);
        heapify(ar, x, 0);
    }
}

int main(){
    int ar[10], n = 10;

    printf("Enter 10 Random Numbers\n\n");
    for(int x = 0; x < n; x++){
        printf("Enter Number for Index [%d]: ",x);
        scanf("%d",&ar[x]);
    }

    printf("\nOriginal Array  -> ");
    printAr(ar,n);

    heapSort(ar,n);

    printf("Sorted Array -> ");
    printAr(ar,n);
}