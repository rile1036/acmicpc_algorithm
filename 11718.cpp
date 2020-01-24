#include<stdio.h>

int main(void){
    char arr[101];
    while(gets(arr)){
    if(arr[0] == '\0')
        break;
    puts(arr);
    }
}