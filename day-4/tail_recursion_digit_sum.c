#include<stdio.h>
int sum(int n, int a){
    if(n == 0){
        return a;
    }
    return sum(n-1, a+n);
}

int main(){
    int n = 4, a=0;
    printf("Input the number to find its Sum of Digits\n");
    scanf("%d",&n);
    int s = sum(n,a);
    printf("%d",s);
    return 0;
}