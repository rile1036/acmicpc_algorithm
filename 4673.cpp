#include<stdio.h>
int d[10036] = {0, };
int Sang(int i) {
	int sang = i;
	if (i >= 10000) 
    { 
        sang += i / 10000; 
        i %= 10000; 
    }
	if (i >= 1000) 
    { 
        sang += i / 1000; 
        i %= 1000; 
    }
	if (i >= 100) 
    { 
        sang += i / 100; 
        i %= 100; 
    }
	if (i >= 10) 
    { 
        sang += i / 10;
        i %= 10; 
    }
	return sang += i;
}
int main() {
	for (int i = 1; i <= 10000; i++) 
    {
		d[Sang(i)] = 1;
		if (!d[i]) printf("%d\n", i);
	}
    return 0;
}


