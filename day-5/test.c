#include<stdio.h>
void test(int *start, int *end){
    int i = 10, j = 50;
    *start = i;
    *end = j;
}
int main(){
    int start =0, end =0;
    test(&start, &end);
    printf("%d %d", start, end);
}
