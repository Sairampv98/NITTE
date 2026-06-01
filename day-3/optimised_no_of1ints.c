#include<stdio.h>

int main(){
    int dec_num =11, count=1;
    int store, temp;
    printf("Enter integer to check the no. o  1's in it: \n");
    scanf("%d", &dec_num);
    if(dec_num==0){
        printf("0");
        return 0;
    }else if(dec_num<0){
        printf("You have entered a -ve integer");
    }
    store = (dec_num&(dec_num-1));
    while(store!=0){
            store &= store-1;
            count++;
    }
    printf("%d",count);
    return 0;
}