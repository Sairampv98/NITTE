#include<stdio.h>
#include<stdlib.h>

int compare(const void *a, const void *b){
    int x = *(const int*)a;
    int y = *(const int*)b;

    return (x>y) - (x<y); //(15>4 = 1) - (15<4 = 0) = 1 for 'x' greater than 'y'
                         //(4>15 = 0) - (4<15 = 1) = -1 for 'y' greater than 'x'
                         //(4>4 = 0) - (4<4 = 0) = 0 for 'y' equal to 'x'
}

    int main(){
    int arr[7] = {100,99,1,2,3,4,5}; //limitation needs to be 
    // initialised with exactly the correct array size and 
    // valid number of elements
    int size = sizeof(arr)/sizeof(int);
    int result =0;
    qsort(arr, size, sizeof(int),compare);
    for(int i=1; i<size; i++){
        if(arr[i] == arr[i-1]){
            result = 6;
            break;
        }
        result = 5; 
    }
    switch(result){
        case 6: printf("The input array has duplicate: True\n"); 
                break;
        case 5: printf("The input array has duplicate: False\n");
                break;
    }
    return 0;
}