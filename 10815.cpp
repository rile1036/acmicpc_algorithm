#include<cstdio>
#include<algorithm>
using namespace std;
int a[500000], n, m, x;
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    sort(a, a + n);
    scanf("%d", &m);
    while (m--) scanf("%d", &x), printf("%d ", binary_search(a, a + n, x));
    return 0;
}