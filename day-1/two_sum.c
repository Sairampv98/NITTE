#include<stdio.h>

int main(){
    int arr[] = {1,3,10,7,5};
    int target = 17;
    int len_arr = sizeof(arr)/sizeof(int);
    for(int i =0; i<len_arr; i++){
        for(int j =0; j<len_arr;j++){
            if(i==j){
                continue;
            }
            if(arr[i]+arr[j]==target){
                printf("%d, %d is the solution for Two sum", i,j);
                return 0;
            }
        }
    }
    printf("There is no solution for Two sum in given test array & target");
    return 0;
}