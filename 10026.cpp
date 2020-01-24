#include<stdio.h>

char arr[101][101];
bool arred[101][101];
int aa[4] = {0,0,-1,1};
int bb[4] = {-1,1,0,0};
int n;
void dfs(int a, int b, char c)
{
    arred[a][b]=1;
    for(int i=0;i<4;i++)
    {
        int x=a+aa[i];
        int y=b+bb[i];
        if(x>=1&&x<=n&&y>=1&&y<=n&&!arred[x][y]&&arr[x][y]==c)
            dfs(x,y,c);
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=1; i<=n;i++)
        for(int j=1; j<=n;j++)
            scanf(" %c",&arr[i][j]);
        int c=0;
    for(int i=1; i<=n;i++)
        for(int j=1; j<=n;j++)
            if(!arred[i][j]){
                dfs(i,j,arr[i][j]);
                c++;
            }
    printf("%d ",c);
    c=0;
    for(int i=1; i<=n;i++)
        for(int j=1; j<=n;j++)
            arred[i][j]=0;
    for(int i=1; i<=n;i++)
        for(int j=1; j<=n;j++)
             if(arr[i][j]=='G'){
                arr[i][j]='R';
            }
    for(int i=1; i<=n;i++)
        for(int j=1; j<=n;j++)
            if(!arred[i][j]){
                dfs(i,j,arr[i][j]);
                c++;
            }
    printf("%d",c);
}