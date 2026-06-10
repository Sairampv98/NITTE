#include<assert.h>
#include<stdio.h>

void process(int *arr, int n){
    assert(arr != NULL);
    assert(n>0);
}

int main(){
    int ar[1];
    int *arr =NULL;
    process(arr, -1);
    return 0;
}