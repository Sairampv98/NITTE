#include<stdio.h>

int main(){
    int n, flag=0;
    printf("Check if a number is a perffect square\n");
    scanf("%d",&n);

    for(int i=1; i<n; i++){
        if(i*i == n){
            printf("%d is the square root of %d", i,n);
            flag = 1;
            return 0;
        }
    }
    if (flag != 1){
        printf("The input number does not have a perfect square");
    }
    return 0;
}