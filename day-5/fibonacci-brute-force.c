#include<stdio.h>

int fibonacci(int n){
    if(n==0)
        return 0;
        return 0;
    if(n==1)
        return 1;
    return fibonacci(n-1) + fibonacci(n-2);
}

int main(){
    int num =4;
    printf("Type a number to check its fibonacci number for\n");
    scanf("%d",&num);
    for(int i =0; i<=num; i++){
        int res = fibonacci(i);
        printf("%d = %d\n",i, res);
    }

    return 0;
}