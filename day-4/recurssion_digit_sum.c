#include<stdio.h>
int sum(int n){
    if(n == 0){
        return 0;
    }
    return n + sum(n-1);
}

int main(){
    int n = 4;
    printf("Input the number to find its factorial\n");
    scanf("%d",&n);
    int s = sum(n);
    return 0;
}