#include<iostream>
#include<stdio.h>
using namespace std;
int matrix[1001][1001];
bool check[1001];
long long d[1001];
int n;

int extract_min(){
	int idx;
	long long minn=100000001;
	for(int i=1;i<=n;i++){
		if(check[i]==0){
			if(d[i]<minn){
				idx=i;
				minn=d[i];
			}
		}
	}
	return idx;
}
int main(void){
	
	int m;
	int start,end;
	int weight;
	scanf("%d",&n);
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			matrix[i][j]=999999;
		}
	}
	scanf("%d",&m);
	for(int i=0;i<=n;i++)
		d[i]=100000000;
	for(int i=0;i<m;i++){
		scanf("%d %d %d",&start,&end,&weight);
		matrix[start][end]=min(weight,matrix[start][end]);
	}
	scanf("%d %d",&start,&end);
	d[start]=0;
	check[start]=1;
	for(int i=1;i<=n;i++){
		if(matrix[start][i]!=999999)
			d[i]=matrix[start][i];
	}
	
	while(1){
		int checkk=0;
		for(int i=1;i<=n;i++)
			if(check[i]==0)
				checkk=1;
		if(checkk==0)
			break;
		int idx=extract_min();
		
		check[idx]=1;
		for(int i=1;i<=n;i++){
			if(matrix[idx][i]!=999999)
				d[i]=min(d[i],d[idx]+matrix[idx][i]);
		}
		
		//printf("%d\n", idx);
	}
	printf("%lld\n",d[end]);
}