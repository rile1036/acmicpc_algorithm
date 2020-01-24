#include <cstdio> 
#include <string.h> 
#include <algorithm>  

using namespace std; 

const int INF=987654321; 
int t, x, y, DP[5010][5010], alpha[26], countX[26][5010], countY[26][5010]; 
char X[5010], Y[5010]; 

void cnt(int len, char str[], int data[][5010]) 
{ 
    for(int i=1 ; i<=len ; i++) 
    { 
	    int idx=str[i]-'A'; 
 	    alpha[idx]++; 
        for(int j=0 ; j<26 ; j++) 
	    { 
 		    if(idx==j) data[j][i]++; 
 		    data[j][i]+=data[j][i-1]; 
 		} 
   } 
} 

void inIt() 
{ 
 	memset(alpha, 0, sizeof(alpha)); 
 	memset(countX, 0, sizeof(countX)); 
 	memset(countY, 0, sizeof(countY)); 
 	cnt(x, X, countX); 
 	cnt(y, Y, countY); 
 	for(int i=0 ; i<5010 ; i++) for(int j=0 ; j<5010 ; j++) DP[i][j]=INF; 
} 

int getCost(int x, int y, char ch) 
{ 
 	int ret=0; 
 	if(countX[ch-'A'][x]+countY[ch-'A'][y]==1) ret-=x+y; 
 	if(countX[ch-'A'][x]+countY[ch-'A'][y]==alpha[ch-'A']) ret+=x+y; 
 	return ret; 
} 

int solution() 
{ 
 	DP[1][0]=DP[0][1]=0; 
 	for(int i=0 ; i<=x ; i++) 
 	{ 
 		for(int j=0 ; j<=y ; j++) 
 		{ 
 			char first=X[i], second=Y[j]; 
 			if(i!=0) DP[i][j]=min(DP[i][j], DP[i-1][j]+getCost(i, j, first)); 
 			if(j!=0) DP[i][j]=min(DP[i][j], DP[i][j-1]+getCost(i, j, second)); 
 		} 
 	} 
 	return DP[x][y]; 
} 

int main(void) 
{ 
 	scanf("%d", &t); 
 	while(t--) 
 	{ 
 		scanf("%s%s", X+1, Y+1); 
 		x=strlen(X+1); y=strlen(Y+1); 
 		inIt();  
 		printf("%d\n", solution()-1); 
 	} 
} 
