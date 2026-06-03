#include<stdio.h>
#include<stdbool.h>

int main(){
    int num, res=2;
    printf("check if a number is a power of 2\n");
    scanf("%d", &num);
    if(num<0){
        printf("only posiitve numbers\n");
        return 0;
    }
    for (int i =0; i<num; i++){
        res *= 2;
        if(res>=num) break;
    }
    if(res != num) printf("False");
    else printf("True");
    return 0;
}