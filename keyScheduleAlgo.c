#include<stdio.h>
#include"swap.h"

int* calculateSArray(char *key){
    int i,*s,j;
    s=malloc(256*sizeof(i));
    for(i = 0;i < 256;i++)
        s[i] = i;
    int keylength = strlen(key);
    //keylength-=1;
//    printf("keylength: %d",keylength);
    j=0;
    for(i = 0;i < 256;i++){
        j = (j + s[i] + key[i % keylength]) % 256;
        int *temp=swapSArrayElements(s,i,j);
        s=temp;
        
    }
    for(i = 0;i < 256; i++)
        printf("%d ",s[i]);
    return s;
}
