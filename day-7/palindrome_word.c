#include<stdio.h>
#include<string.h>

int main(){
    int counter = 0;
    char a[4] = {'P','O','T'};
    int size = strlen(a);
    for(int i =0; a[i]!='\0'; i++){
        if (a[i] != a[size-i-1]){
            printf("It is not a palindrom");
            return 0;
        }
    }
    printf("It is a palindrom");
    return 0;
}