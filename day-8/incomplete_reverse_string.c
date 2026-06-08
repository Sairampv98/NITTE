#include<stdio.h>
#include<ctype.h>
#include<string.h>

int main(){
    char a[] ="a good example";
    //int 14 = strlen(a); // minus 1 for actual array size
    char out[14];
    int end=0, start=0, current =0, t=0;
    
    for(int i= 13; i>=0; i--){
        if(a[i]!=' '){ //might have to add this? ||a[i]!='\0'
            end = i; // end does not change
            for(int j=i; j>=0;j--){//have to finish everything in this loop
                if(a[j]==' '&&j<13){//should always be less than 13
                    start =j+1;
                    for(current; (start<=end&&current<13);current++){
                        out[current] = a[start];
                        start++;                        
                    }
                    //out[current+1]           
                   }
                
            }
        }
    }
    for(int k=0; k<14;k++){
        printf("%s", *out);
    }
    printf("%c",a[13]);
    return 0;
}
    


    
