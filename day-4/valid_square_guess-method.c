#include<stdio.h>
#include<math.h>
#include<stdbool.h>

int main(){
    float num=3025, check = 0.000001, temp;
    printf("Check if a number is a perffect square\n");
    scanf("%f",&num);
    if(num<0){
        printf("The input number is a negative number");
        return 0;
    }else if(num == 0){
        printf("0 is the perfect square of 0");
        return 0;
    }
    float guess = num/1234; //can be any vaule
    while(true){
        temp = (guess+(num/guess))/2; 
        //mistake was num/2 instead of num divided by guess
        if (fabs(temp - guess) <= check){
            break;
        }
        guess = temp;
    }
    int sq_root = (int)floor(guess);
    if(sq_root*sq_root == (int)num){
        printf("%d is the square root of %d", sq_root,(int)num);
    }else{
        printf("The input number does not have a perfect square");
    }
    return 0;
}