#include<stdio.h>

int main(void) {
    int min;
    int A, i;
    int sum = 0;
    int num = 0;

    scanf("%d", &min);
    scanf("%d", &A);
    
    for (min; min <= A; min++) {
        for (i = 2; i <= min; i++) {        
            if (min == 2) {
                num = 2;
                sum = sum + 2;
                break;
            }

            if (min % i == 0) {
                break;
            }
            
            if (i == min - 1) {
                if (num == 0) 
                {
                    num = min;
                }
                sum = sum + min;
                break;
            }
        }
    }
    
    if (sum != 0) {
        printf("%d\n", sum);
        printf("%d\n", num);
    }
    else {
        printf("-1");
    }

    return 0;
}
