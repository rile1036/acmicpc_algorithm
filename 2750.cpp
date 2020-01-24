#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n; scanf("%d",&n);
	int q[1000];
	for(int i=0; i<n; i++) scanf("%d",&q[i]);
	sort(q, q+n);
	for(int i=0; i<n; i++) printf("%d\n",q[i]);
}