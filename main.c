#include<stdio.h>
#include"keyScheduleAlgo.h"
#include"generateOutput.h"

void main(char** argv, int argc){
    char key1[128] ,msg[1000];
    int *s;
    printf("Enter Key: ");
    scanf("%128s",key1);
    printf("\n\n----Atfer key input----");
    s = calculateSArray(key1);
    printf("\n\n Enter Message: ");
    scanf("%1000s",msg);
    
    generateOutput(msg,s);
}
