#include <stdio.h>

//yung function na to ay para sa pag print nang laman ng array wag nyo to pansinin 
void printArray(int * arr, int n){
    int x = 0;
    printf("Array -> [");
    for(; x < n; x++) printf("%d%s",arr[x],x == n-1? "":", ");
    printf("]\n");
}

int main(){ 
    int arr [] = {30,18,3,6,40,1}, n = 6;
    printArray(arr, n);

    int x;

    //Insertion Sort
    for(x = 1; x < n; x++){
        int y = x-1;
        int v1 = arr[x];
        while(y >= 0 && v1 < arr[y]){
            arr[y + 1] = arr[y];
            --y;
        }
        arr[y + 1] = v1;
    }

    printArray(arr,n);
}

                /*
                    Basically you pick a value
                    then ichecheck mo kung yung value nayon ay mas mababa sa current selected value
                    no need to create temp variable before swapping kasi nasa pick value na sya
                    then set arr[y + 1] value as pick value
                */