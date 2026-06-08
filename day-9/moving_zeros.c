#include<stdio.h>

int main(){ 
    int arr[] ={1,5,4,0,7,9,1}; // expected output {1,5,4,7,9,1,0}
    int size = sizeof(arr)/sizeof(int);
    int temp=0;
    for(int i=0; i<size; i++){
        if(arr[i]==0){
            for(int j=i;j<size;j++){
                if(j+1<size){
                    temp=arr[j+1];
                    arr[j]=temp;
                    arr[j+1]=0;
                }
            }
        }
    }
    for(int k=0; k<size;k++){
        printf("%d", arr[k]);
    }
    
}