#include<stdio.h>

int fib_tail(int n, int a, int b){
    if(n==0) {
        return a;  
    }
    return fib_tail(n-1, b, a+b); 
}
int fibonacci(int n){
    return fib_tail(n, 0,1);
}

int main(){
    int num =4,res =0;
    printf("Type a number to check its fibonacci number for\n");
    scanf("%d",&num);
    for(int i =0; i<=num; i++){
        res = fibonacci(i);
        
    }
    printf("%d = %d\n",num, res);
    return 0;
}