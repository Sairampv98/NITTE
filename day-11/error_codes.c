#include<errno.h>
#include<string.h>
#include<stdio.h>

int main(){
    FILE *fp = fopen("nonexistant.txt", "r");
    if(fp == NULL){
        printf("Error Code: %d",errno);
        printf("\nfopen failed");
    }
    return 0;
}

