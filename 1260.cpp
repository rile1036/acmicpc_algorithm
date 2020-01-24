#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

int N, M, V;
bool e[1001][1001];
bool visit[1001];
//DFS
void dfs(int a){
	printf("%d ", a);
	visit[a] = true;
	for (int i = 1; i <= N; i++){
		if (!visit[i] && e[a][i]) {
			dfs(i);
		}
	}
}
//BFS
void bfs(int a){
	queue<int> q;
	q.push(a);
	visit[a] = true;
	while (!q.empty()){
		int pres = q.front(); q.pop();
		printf("%d ", pres);
		for (int i = 1; i <= N; i++){
			if (!visit[i] && e[pres][i]) {
				//visit은 반드시 여기!
				visit[i] = true;
				q.push(i);
			}
		}
	}
}

int main(){
	scanf("%d %d %d", &N, &M, &V);

	memset(e, false, sizeof(e));
	for (int i = 0; i < M; i++){
		int v, u;
		scanf("%d %d", &v, &u);
		e[v][u] = true; e[u][v] = true;
	}

	memset(visit, false, sizeof(visit));
	dfs(V);
	printf("\n");
	memset(visit, false, sizeof(visit));
	bfs(V);
}