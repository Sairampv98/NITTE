#include<stdio.h>
const int hash_size = 1000; //global variable
int hash_key[1000];
int hash_value[1000];
int check=0;

int check_hash(int key, int value){
    for(int i=0; i<hash_size; i++){
        if(check==hash_key[i]){
            return hash_value[i];
        }
    }
    return -1;
}
int main(){
    int input_array[] = {75,15,89,93,105};
    int target = 194, found=-1;
    int size = sizeof(input_array)/sizeof(int);
    for(int i=0; i<size; i++){
        if(target>input_array[i]){
            check = target - input_array[i];
            hash_key[i]=input_array[i];
            hash_value[i]=i;
            found = check_hash(input_array[i], i);
            if(found != -1){
                printf("found solution at %d & %d", i, found);
                return 0;
            }
        }
        check = input_array[i] - target;
        hash_key[i]=input_array[i];
        hash_value[i]=i;
        found = check_hash(input_array[i], i);
        if(found != -1){
                printf("found solution at %d & %d", i, found);
                return 0;
        }
    }

    return 0;
}