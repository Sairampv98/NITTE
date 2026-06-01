#include<stdio.h>

int main(){
    int n;
    printf("Put a 2 digit +ve integer to print fizzbuzz\n");
    scanf("%d",&n);
    for (int i =1; i<=n;i++){
        if(i%3==0){
            printf("fizz");
        }
        if(i%5==0){
            printf("Buzz");
        }else{
            printf("%d ,",i);
        }
    }
    return 0;
}