#include<stdio.h>
void print_number(int i){
    printf("%d: %d\n", i,i);
}
void print_fizz(int i){
    printf("%d: Fizz\n", i);
}
void print_buzz(int i){
    printf("%d: Buzz\n", i);
}
void print_fizzbuzz(int i){
    printf("%d: FizzBuzz\n", i);
}
int main(){
//we are converting void to int to loop through the void array using the iterator
    void (*dispatch_table[4])(int) = {
        print_number,print_fizz, print_buzz, print_fizzbuzz
    };
    int n, flag;
    printf("Put a 2 digit +ve integer to print fizzbuzz\n");
    scanf("%d",&n);
    for (int i =1; i<=n;i++){
        flag =0;
        if(i%3==0){
            flag |=1;
        }
        if(i%5==0){
            flag |=2;
        }
        if(i%3==0 && i%5==0){
            flag |=3;
        }
        dispatch_table[flag](i);
    }  
    return 0;
}