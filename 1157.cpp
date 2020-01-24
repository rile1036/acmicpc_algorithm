#include<stdio.h>
#include<string.h>
int main()
{
	int alpha[26] = { 0, };
	char str[1000001];
    scanf("%s", &str);
    int len = strlen(str);
	for (int i = 0; i < len; i++) {
		if (str[i] < 97) 
			alpha[str[i] - 65]++;
		else
			alpha[str[i] - 97]++;
	}
    
	int cnt = 0, max = alpha[0];
    int i = 0;
    while(i < 26){
        if (max < alpha[i])
            max = alpha[i];
        i++;
    }
    int idx;
	for (int i = 0; i < 26; i++) {
		if (max == alpha[i]) {
			cnt++;
            if(cnt ==1)
            idx = i;    
		}
	}
    int index = idx + 65;
	if (cnt >= 2)
		printf("?");
	else
	printf("%c", index);
    return 0;
}