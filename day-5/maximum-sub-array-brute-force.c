#include<stdio.h>
#include<stdbool.h>

int main(){
    int arr[]= {-2,1,-3,4,-1,2,1,-5,4};
    int start = 0;
    int end = 0;
    int num= sizeof(arr)/sizeof(int);
    
    for(int i=0; i<num;i++){
        int sum =0, temp_sum=arr[i];
        start++;
        for(int j=0;i<num;j++){
            end++;
            sum = arr[j];
            for(int k=0;i<num;k++){
                if(j!=k) sum += arr[k]; //doubtful if it works
                if(k<=j&&k!=0){ // this too
                    temp_sum = temp_sum+arr[k];
                }
                if(temp_sum>sum) { //this is ok i think
                    sum=temp_sum;
                    start = j;
                    end = k;
                }

            }
        }
    }
    return 0;
}