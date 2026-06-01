#include<stdio.h>

int main(){
    int original[] = {1,5,7,10};
    int target = 11, len = sizeof(original)/sizeof(int);
    int left=0, right = len -1;
    while (left<right){
        int sum = original[left] + original[right];
        if(original[left]+original[right]==target){
            printf("%d & %d is the solution", left+1, right+1);
            return 0;
        }else if(sum> target){
            right --;
        }else if(sum < target){
            left ++;
        }
    }
    printf("No solution");
    return 0;
}