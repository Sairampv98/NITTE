#include<stdio.h>
#include<string.h>
//the matrix multiplication is not returning the expected value
typedef struct{
    long long mat[2][2];
}matrix;

matrix mat_multiply(matrix a, matrix b){
    matrix c;
    memset(c.mat, 0, sizeof(c.mat));
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            c.mat[i][j] += a.mat[i][j]*b.mat[i][j];
        }
    }
    return c;
}

matrix mat_power(matrix m, int n){
    matrix result;
    result.mat[0][0] = 1; 
    result.mat[0][1] = 1;
    result.mat[1][0] = 1;
    result.mat[1][1] = 0;

    while(n>0){
        if( n& 1){
            result = mat_multiply(result,m);
        }
        n>>=1;
    }
    return result;
}

long long fib_matrix(int n){
    if(n==0) return 0;
    if(n==1) return 1;

    matrix fib_base;
    fib_base.mat[0][0] = 1; 
    fib_base.mat[0][1] = 1;
    fib_base.mat[1][0] = 1;
    fib_base.mat[1][1] = 0;

    matrix result = mat_power(fib_base,n);
    return result.mat[0][1];
}

int main(){
    int num =4;
    long long mat_res, iteration_result;
    printf("Type a number to check its fibonacci number for\n");
    scanf("%d",&num);
    for(int i =0; i<=num; i++){
        mat_res = fib_matrix(i);
        if(i==0) iteration_result = 0;
        else if(i==1) iteration_result = 1;
        else{
            long long prev = 0, current =1;
            for(int j =2; j<= i; j++){
                long long next = prev+current;
                prev =current; current = next;
            }
            iteration_result = current;
        } 
        printf("i=%d, iteration_result=%d, mat_result=%d\n", i, iteration_result, mat_res);
    }

    return 0;
}