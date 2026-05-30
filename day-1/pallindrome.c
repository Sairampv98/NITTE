#include <stdio.h>

int main(){
    int ispallindrome, remainder, temp, reversed = 0;

    printf("Type a number that you want to check if it is a palindrome?");
    scanf("%d", &ispallindrome);
    temp= ispallindrome;
    while(temp != 0){
        remainder = temp%10;
        reversed = reversed*10 + remainder;
        temp = temp/10;
    }
    if(ispallindrome/10 == 0){
        printf("%d is not a palindrome",ispallindrome);
        return 0;
    }
    if(reversed == ispallindrome){
        printf("%d is a pallindrome",ispallindrome);
    }else{
        printf("%d is not a palindrome",ispallindrome);
    }
    return 0;
}