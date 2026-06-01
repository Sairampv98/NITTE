#include<stdio.h>
#include<string.h>
int main(){
    int n;
    printf("Put a 2 digit +ve integer to print fizzbuzz\n");
    scanf("%d",&n);
    for (int i =1; i<=n;i++){
        char arr[50];
        arr[0] = '\0';
        if(i%3==0){
            strcat(arr, "fizz");
        }
        if(i%5==0){
            strcat(arr, "Buzz");
        }else{
            sprintf(arr, "%d",i);
        }
        printf("%d: %s\n", i, arr);
    }
    return 0;
}