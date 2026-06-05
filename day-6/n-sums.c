#include<stdio.h>
#include<stdbool.h>

bool n_sums(int *arr, int size, int pos, int target){
    if(target==0) {
        return true;  
    }
    if(pos==size){
        return false;
    } 
    return n_sums(arr, size, pos+1, target-arr[pos]) || 
    n_sums(arr, size, pos+1, target);
}

int main(){
    int arr[] = {1,3,10,7,5};
    int target = -1;
    int size = sizeof(arr)/sizeof(int);
    bool isfound = n_sums(arr,size,0,target);
    if(isfound==true){
        printf("The target was found in the array\n");
    }else{
        printf("The target was not found in the array\n");
    }
    printf("{1,3,10,7,5}");
    
    return 0;
}