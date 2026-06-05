#include<stdio.h>
#include<limits.h>

int main(){
    int arr[]= {-2,1,-3,4,-1,2,1,-5,4}; 
    //answer 6, start = 3,end =6    
    int start = 0;
    int end = 0;
    int sum = 0, temp_sum=0, temp=0;
    int size= sizeof(arr)/sizeof(int);
    for(int i=0; i<size; i++){
        if(sum>=arr[i]){ 
            sum = arr[i];
        }
    }
    for(int i=0; i<size;i++){
//eliminated repeated values from loop using a+b=b+a
        for(int j=i;j<size;j++){
            temp += arr[j]; 
            for(int k=0;k<size;k++){
                temp_sum += arr[k];
                if(temp_sum>temp){
                    sum = temp_sum;
                    start = i;
                    end = j;
                }
                }
            }
        }
    printf("The best sub array indexes \n");
    printf("are %d & %d and they add up to %d",start,end, sum);
    return 0;
}