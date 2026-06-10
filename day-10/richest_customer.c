#include<stdio.h>

int main(){
    int arr[3][3] = {{2,7,8},{7,1,3},{1,9,5}};
    int max =0, temp =0, customer =0;
    for(int i=0; i<3;i++){
        for(int j=0; j<3; j++){
            temp += arr[i][j];
            if(temp>max){
                max = temp;
                customer = i;
            }
        }
        temp = 0;
    }
    printf("The richest customer is : %d and he has %d wealth", customer, max);
    return 0;
}