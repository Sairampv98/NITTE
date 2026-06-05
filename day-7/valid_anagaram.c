#include<stdio.h>

int main(){
    int counter = 0;
    char a[4] = {'T','O','P'};
    char b[4] = {'P','O','P'};
    for(int i =0; a[i]!='\0'; i++){
        counter += (a[i]-'a');
    }
    for(int i =0; b[i]!='\0'; i++){
        counter -= (b[i]-'a');
    }
    if (counter == 0){
        printf("It is a anagram");
    }else{
        printf("It is not a anagram");
    }
    return 0;
}