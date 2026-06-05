#include<stdio.h>
#include<string.h>
int main(){
    int num =4;
    long long iteration_result;
    printf("Type a number to check (using loops) its fibonacci number for\n");
    scanf("%d",&num);
    for(int i =0; i<=num; i++){
        if(i==0) iteration_result = 0;
        else if(i==1) iteration_result = 1;
        else{
            long long prev = 0, current =1;
            for(int j =2; j<= i; j++){
                long long next = prev+current;
                prev =current; current = next;
            }
            iteration_result = current;
        } 
        printf("i=%d, iteration_result=%lld\n", i, iteration_result);
    }

    return 0;
}