#include <stdio.h>
#include <iostream>
using namespace std;
int main(void)
{
    int value[500001];
    int stack1[500001];
    int stack2[500001] = {0, };
    int count = 0;
    int top = 0;
    scanf("%d\n", &count);
    
    for (int i = 0 ; i < count; i++)
    {
        scanf("%d ",&value[i]);
    }
    for (int i = count - 1 ; i >= 0; i--)
    {
        while(top > 0 && value[i] >= value[stack1[top-1]])
        {
        stack2[stack1[(top--)-1]] = i + 1;
        }
        stack1[top++] = i; 
    }
    for (int i = 0; i < count; i++){
        printf("%d ",stack2[i]);
    }
}

