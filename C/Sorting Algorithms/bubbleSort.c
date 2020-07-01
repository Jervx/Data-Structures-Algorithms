
//JERBEE PARAGAS

#include <stdio.h>


void printArray(int arr[], int n){
    int x = 0;
    printf("Array -> [");
    for(; x < n; x++) printf("%d%s",arr[x],x == n-1? "":", ");
    printf("]\n");
}

int main(){ 
    int arr [] = {30,18,3,6,40,1};
    int n = 6;
    printArray(arr, n);
    int x = 0, y = 0;

    //bubble sort
    for(x = 0; x < n-1; x++)
        for(y = 0; y < n-x-1; y++)
            if(arr[y] > arr[y+1]){
                int t = arr[y];
                arr[y] = arr[y + 1];
                arr[y + 1] = t;
            }

    printArray(arr,n);
}

    /*
        Condition kung ang current value is > sa next value
        kung mas malaki yung current val sa next val then swap natin sila
        wag kalimutan gumamit ng temporary variable before swap kasi para hindi maoverwritten kapag mag saswap
    */