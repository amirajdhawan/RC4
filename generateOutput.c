#include<stdio.h>
#include"swap.h"
#include<string.h>

void generateOutput(char msg[], int s[]){
    int i,j,t,k;
    i = j = 0;
    char cipherByte;
    int msglen = strlen(msg);
    printf("\n%d\n\n",msglen);
    for(k = 0;k < msglen;k++){
        i = (i + 1) % 256;
        j = (j + s[i]) % 256;
        s = swapSArrayElements(s, i , j);
        t = (s[i] + s[j]) % 256;
        cipherByte = s[t]^msg[k];
        printf("%c  %d\n",msg[k],s[t]);
        printf("%.2X   %d\n",cipherByte,k);
    }
    printf("\n");
}
