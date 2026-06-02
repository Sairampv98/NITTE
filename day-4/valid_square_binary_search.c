#include<stdio.h>

int main(){
    int n, hi, mid, flag= 0;
    printf("Check if a number is a perffect square\n");
    scanf("%d",&n);
    hi = n;
    mid = hi/2;
    while(mid*mid>n){
        hi = mid;
        mid = hi/2;
    }
    for(int i=mid; i<hi;i++){
        if(i*i==n){
            flag = 1;
            printf("%d is the square root of %d", i,n);
            break;
        }
    }
    if(flag==0){
        printf("The input number does not have a perfect square");
    }
    return 0;
}