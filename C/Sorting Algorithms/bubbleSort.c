#include <stdio.h>
#include <stdlib.h>

//this function is for printing the array content
//yung function na to ay para sa pag print nang laman ng array
void printArray(int * arr, int n){
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
    for(x = 0; x < n; x++){
        for(y = 0; y < n-x-1; y++){
            //condition if the current selected value is greater than the next selected value
            if(arr[y] > arr[y+1]){
                //if current value > next value then swap current and next
                int t = arr[y];
                arr[y] = arr[y + 1];
                arr[y + 1] = t;
            }
        }
    }

    printArray(arr,n);

}