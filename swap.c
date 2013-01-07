#include<stdio.h>

int* swapSArrayElements(int s[], int i, int j){
    int temp;
    temp = s[i];
    s[i] = s[j];
    s[j] = temp;
    return s;
}
