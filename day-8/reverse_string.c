#include<stdio.h>
#include<ctype.h>
#include<string.h>

int main(){
    char a[] ="a good example";
    int len = strlen(a); 
    char out[100]; 
    int end=0, start=0, current =0, t=0;
    
    for(int i= len-1; i>=0; i--){
        if((a[i]!=' ')&&(i == len-1 || a[i+1] == ' ')){ 
            end = i; 
            for(int j=i; j>=0;j--){
                if(a[j]==' '){
                    start =j+1;
                    break;
                }
                if(j == 0){
                    start = 0; 
                    break;
                }     
            }
        for(; start<=end;start++){
                out[current] = a[start];
                current++;                        
            } 
        out[current] = ' ';
        current++;         
        }
    }
    out[current-1] = '\0';
    printf("%s", out);
    return 0;
}
    


    
