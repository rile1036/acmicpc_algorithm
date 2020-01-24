#include<cstdio>
#include<cstring>


using namespace std;
int main()
{
    char s[1000001];
    int count = 0;
    int ln = strlen(s);
    int i;  
    int num = 0;
    
    gets(s);
    for(i = 0; s[i] != 0; ++i)
    {
            if (s[i+1] == '\0' && ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')))
                ++count;
            if(num == 0 && s[i] != ' ')
                num = 1;
            else if((num == 1 && s[i] == ' ') || s[i] == '\n')
            {
                ++count;
                num = 0;
            }
    }

    printf("%d", count);
    return 0;
}