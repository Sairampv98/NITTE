#include<stdio.h>
#include<string.h>
int memo[100] ;

int fib_memo(int n){
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    if(memo[n] != -1){
        return memo[n];
    }
    memo[n] = fib_memo(n-1) + fib_memo(n-2);
    return memo[n];
}


int main(){
    int num =4,res=0;
    printf("Type a number to check (using memoisation) its fibonacci number for\n");
    scanf("%d",&num);
    memset(memo,-1,sizeof(memo));
    
    res = fib_memo(num);
    
    printf("%d = %d",  num,res);
    
    return 0;
}