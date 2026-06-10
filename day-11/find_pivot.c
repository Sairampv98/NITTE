#include<stdio.h>

int main(){
    int arr[] = {1,7,3,6,5,6};
    int len = sizeof(arr)/sizeof(int);
    int pivot,sum =0, left=0, right=0;
    for(int i=0; i<len; i++){
        sum+=arr[i];
    }
    for(int i=0; i<len; i++){
        right = sum-left-arr[i];
        if(left == right){
            pivot = i;
            break;
        }
        left +=arr[i];
        pivot = -1;
    }
    if(pivot == -1){
        printf("The pivot is non existant");
    }else if(pivot == 0){
        printf("The pivot is found at position %d and its value is %d", pivot, arr[pivot]);
    }else {
        printf("The pivot is found at position %d and its value is %d", pivot, arr[pivot]);
    }
    
    return 0;
}