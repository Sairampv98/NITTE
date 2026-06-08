#include<stdio.h>
#include<strings.h>

int main(){
    char string[] = "abcabcbb";
    int size = strlen(string);
    int max=0;
    int start =0, end =0;
    for(int i=0; i<size; i++){
        int repeat[256] = {0};
        for(int j=i; j<size; j++){
            int c = string[j];
            if(repeat[c]) break;
            repeat[c] = 1;
            int current = j - i +1;
            if(current>max){
                max = current;
                start =i;
                end = j;
            }
        }
    }
    if(end>=0){
        for(int k=start; k<=end; k++){
            printf("%c", string[k]);
        }
        printf("\nstart: %d and end: %d", start, end);
    } 
    printf("\nmax length: %d", max);
    return 0;
}