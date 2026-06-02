#include<stdio.h>

int main(){
    int n, counter3 =0, counter5 =0;
    int fizz, buzz;
    printf("Put a 2 digit +ve integer to print fizzbuzz\n");
    scanf("%d",&n);
    for (int i =1; i<=n;i++){
        counter3++;
        counter5++;
        fizz = 0;
        buzz = 0;
        if(counter3==3){
            fizz =1;
            counter3 = 0;
        }
        if(counter5==5){
            buzz =1;
            counter5 =0;
        }
        if(fizz && buzz){
            printf("%d: FizzBuzz\n", i);
        }else if(buzz == 1){
            printf("%d: Buzz\n", i);
        }else if(fizz == 1){
            printf("%d: Fizz\n", i);
        }else{
            printf("%d: %d\n", i,i);
        }
    }
    return 0;
}