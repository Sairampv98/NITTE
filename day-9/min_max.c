#include<stdio.h>

void min_max(int *arr, int arr_size, int *min, int *max){
    int min_pos =0, max_pos =0;
    for(int i=0; i<arr_size; i++){
        if(arr[max_pos]<arr[i]){
            max_pos = i;
            *max = max_pos;
        }
        if(arr[min_pos]>arr[i]){
            min_pos = i;
            *min = min_pos;
        }
    }
}

int main(){ 
    int arr[] ={3,1,4,1,5,9,2,6,5,3};
    int min_pos = 0, max_pos=0;
    int size = sizeof(arr)/sizeof(int);
    min_max(arr, size, &min_pos, &max_pos);
    printf("Min = %d\t Max = %d",arr[min_pos], arr[max_pos]);
}