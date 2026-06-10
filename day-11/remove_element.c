#include<stdio.h>

int main(){ 
    int arr[7] ={1,5,4,0,7,9,1}; 
    int size = sizeof(arr)/sizeof(int);
    int target=1, temp=0, duplicate=0;
    for(int i=0; i<size; i++){
        if(arr[i]==target){
            duplicate++;
            for(int j=i;j<size;j++){
                if(j+1<size){
                    temp=arr[j+1];
                    arr[j]=temp;
                    arr[j+1]=0;
                }
            }
        }else{
            duplicate = -1;
        }
    }
    
    if(duplicate == -1){
        printf("Duplicate is non existant");
    }else {
        printf("---\nDuplicate is found %d times and removed\n", duplicate);
        printf("---\nFinal size of array is %d \n---\n",size-target);
        printf("Final array:\n");
        for(int k=0; k<(size-target);k++){
        printf("%d", arr[k]);
        }
    }

    return 0;
}