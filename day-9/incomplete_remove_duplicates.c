#include<stdio.h>

int main(){ 
    int arr[] ={0,1,1,2,2,3,4}; 
    // expected output {0,1,2,3,4,0,0}
    int size = sizeof(arr)/sizeof(int);
    int count=0, pos =0;
    for(int i=0; i<size; i++){
        for(int j=i+1;j<=size-1;j++){
            if(arr[i]==arr[j]) {
            }
        }
    for(int k=0; k<size;k++){
        printf("%d", arr[k]);
    }
    
}