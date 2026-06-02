#include<stdio.h>

int main(){
    int n, flag =0;
    printf("Put a 2 digit +ve integer to print fizzbuzz\n");
    scanf("%d",&n);
    for (int i =1; i<=n;i++){
        if(i%3==0){
            flag |=1;
        }
        if(i%5==0){
            flag |=2;
        }
        if(i%3==0 && i%5==0){
            flag |=3;
        }
        switch(flag){
            case 0: printf("%d: %d\n",i,i);
            break; 
            case 1: printf("%d: Fizz\n",i);
            flag = 0;
            break;
            case 2: printf("%d: Buzz\n",i);
            flag = 0;
            break;
            case 3: printf("%d: FizzBuzz\n",i);
            flag = 0;
            break;
        }
    }
    return 0;
}
    