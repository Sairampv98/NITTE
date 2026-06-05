#include<stdio.h>

int main(){
    int n;
    printf("Input the length of right angled triangle\n");
    scanf("%d",&n);

    for(int i=1; i<n; i++){
        printf("\n");
        for(int j=1; j<n;j++){
            if(j==1){
            printf("* ");
            }
            if(i==j){
                printf("* ");
            }
            if(j>=0 && j<i){
                printf("* ");
            }
        }  
    }
    
    return 0;
}