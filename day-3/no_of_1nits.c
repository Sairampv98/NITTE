#include<stdio.h>

int main(){
    int dec_num, count=1, chk=0, single=1, store;

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
            chk = store & single;
            if(chk==1){
                count +=1;
            }
            store = store>>1
        ;
    }
    printf("%d",count);
    return 0;
}