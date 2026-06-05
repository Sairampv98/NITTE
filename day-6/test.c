#include<stdio.h>
#include<string.h>

typedef struct{
    long long mat[2][2];
}matrix;

matrix mat_multiply(matrix a, matrix b){
    matrix c;
    memset(c.mat, 0, sizeof(c.mat));
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            if(i==0&&j==0){
                c.mat[i][j] += ((a.mat[i][j]*b.mat[i][j])+(a.mat[i][j+1]*b.mat[i+1][j]));
            }else if(i==0&&j==1){
                c.mat[i][j] += ((a.mat[i][j]*b.mat[i+1][j])+(a.mat[i][j-1]*b.mat[i][j]));
            }else if(i==1&&j==0){
                c.mat[i][j] += ((a.mat[i][j]*b.mat[i-1][j])+(a.mat[i][j+1]*b.mat[i][j]));
            }else if(i==1&&j==1){
                c.mat[i][j] += ((a.mat[i][j-1]*b.mat[i-1][j])+(a.mat[i][j]*b.mat[i][j]));
            }
        }
    }
    return c;
}

matrix mat_power(int n){
    matrix final_result, square_result;
    final_result.mat[0][0] = 1; final_result.mat[0][1] = 1;
    final_result.mat[1][0] = 1; final_result.mat[1][1] = 0;
    int iterations=0;
    
    if(n%2==0){
        iterations = n/2;
        square_result = mat_multiply(final_result, final_result);
        final_result = square_result;
        while(iterations !=1){
            final_result = mat_multiply(final_result, square_result);
            iterations -=1;
        }
    }else{
        iterations = (n-1)/2;
        matrix result;
        result.mat[0][0] = 1; result.mat[0][1] = 1;
        result.mat[1][0] = 1; result.mat[1][1] = 0;
        square_result = mat_multiply(final_result, final_result);
        final_result = square_result;
        while(iterations !=1){
            final_result = mat_multiply(final_result, square_result); 
            iterations -=1;
        }
        final_result = mat_multiply(final_result, result);
    }
    return final_result;
}


int main(){
    /*
    matrix a, b, res;
    a.mat[0][0] = 1; a.mat[0][1] = 1; 
    a.mat[1][0] = 1; a.mat[1][1] = 0;

    b.mat[0][0] = 2; b.mat[0][1] = 1;
    b.mat[1][0] = 1; b.mat[1][1] = 1;
    */
    int num = 9;
    matrix res = mat_power(num);
    printf("%lld    %lld\n", res.mat[0][0],res.mat[0][1]);
    printf("%lld    %lld",res.mat[1][0],res.mat[1][1]);
    return 0;
}
