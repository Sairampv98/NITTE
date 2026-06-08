#include<stdio.h>

int main(){ 
    int nums1[] ={7,9,11,0,0,0}; 
    int nums2[] ={1,12,14};
    int m = 3, n= 3, temp=0; //update these values accordingly
    for(int i=0; i<n;i++){
        nums1[m+i]=nums2[i];
    }
    for(int i=0; i<m+n;i++){
        for(int j=0; j<m+n;j++){
            if(nums1[i]<nums1[j]){
                temp = nums1[j];
                nums1[j]=nums1[i];
                nums1[i]=temp;
            }
        }
    }
    for(int k=0; k<(m+n);k++){
        printf("%d ", nums1[k]);
    }
    return 0;    
}