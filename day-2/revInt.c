#include<stdio.h>

int main(){
    int Max = 2147483647;
    int isNegative =0;
    int original, remainder, reversed =0, temp;
    printf("Input your Signed 32 bit integer to reverse\n");
    scanf("%d",&original);
    //original = -1200000000; 
    if (original < 0){
        temp = original * -1;
        isNegative = 1;
    }else{
        temp = original;
    }
    while(temp!=0){
        remainder = temp%10;
        reversed = reversed *10 + remainder;
        temp /= 10;
    }

    if(isNegative != 0){
        reversed *= -1;
    }
    if (reversed >1000000000 || reversed < -1000000000){
        printf("Input integer is greater than 32bit");
        printf("hence reversed number is 0");
        return 0;
    }
    printf("Input integer is %d & reversed int is %d", original, reversed);
    return 0;
}