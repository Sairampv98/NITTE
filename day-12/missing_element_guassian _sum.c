#include<stdio.h>

int main(){
    int arr[]={9,6,4,2,3,5,7,0,1};
    int size = sizeof(arr)/sizeof(int);
    int max=0;
    int gSum=0;
    int actualSum=0;
    for(int i = 0;i<size;i++){
        if(arr[i]>max){
            max = arr[i];
        }
    }
    gSum = (max * (max-1))/2 ; 
    for(int j=1; j<max; j++){
        actualSum += arr[j];
    }
    printf("The missing number in range 0 to %d");
        printf("is:\n%d", max, gSum-actualSum);
    return 0;
}