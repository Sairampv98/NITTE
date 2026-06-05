#include<stdio.h>
#include<limits.h>

int kadane(int *nums, int n, int *start, int *end){
    int current_sum =nums[0];
    int max_sum = nums[0];
    int temp_start = 0;

    for(int j =1;j<n; j++){
        if(nums[j]>current_sum+nums[j]){
            current_sum = nums[j];
            temp_start = j;
        }else {
            current_sum = current_sum +nums[j];
        }
        if(current_sum > max_sum){
            max_sum = current_sum;
            *start = temp_start;
            *end = j;
        }
    }
    return max_sum;
}

int main(){
    int arr[]= {50,72,64,-50,0,-71};
    //arr[] = {-2,1,-3,4,-1,2,1,-5,4}; 
    //answer 6, start = 3,end =6    
    int size= sizeof(arr)/sizeof(int);
    int temp_value =0;
    int start = 0, end =0;
    int sum = kadane(arr, size, &start, &end);
    
    printf("The best sub array indexes \n");
    printf("are %d & %d and they add up to %d",start,end, sum);
    return 0;
}