#include<stdio.h>

int main(){ 
    int arr[] ={0,1,1,2,2,3,4}; 
    // expected output {0,1,2,3,4,0,0}
    int size = sizeof(arr)/sizeof(int);
    int read, write =1;
    /*for(int i=0; i<size; i++){
        if(arr[i]==arr[pos]){
            for(int j=i+1;j<=size-1;j++){
                if(arr[i]!=arr[j]){
                    arr[i+1]=arr[j];
                    break;
                }
            }
            size--;
            i--;
        }
    }    
    for(int k=0; k<size;k++){
        arr[k] = 0;
    }
    */
    for(read = 1;read<size; read++){
        if(arr[read]!=arr[write-1]){
            arr[write++]=arr[read];
        }
    }
    for(int i =write; i<size; i++){
        arr[i]=0;
    }
    for(int l=0; l<size;l++){
        printf("%d", arr[l]);
    }
    
}