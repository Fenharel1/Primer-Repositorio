#include <bits/stdc++.h>

using namespace std;

const int MAX = 1005;

vector <int> g[MAX];
int visited[MAX];

void bfs(int u) {
	queue <int> q;
	q.push(u);
	visited[u] = 1;
	while (!q.empty()) {
		u = q.front();
		q.pop();
		for (int i = 0; i < g[u].size(); i++) {
			int v = g[u][i];
			if (visited[v] == 0) {
				visited[v] = 1;
				q.push(v);
			}
		}
	}
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		g[x - 1].push_back(y - 1);
		g[y - 1].push_back(x - 1);
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (visited[i] == 0) {
			cnt++;
			bfs(i);
		}
	}
	printf("%d\n", cnt);
	return 0;
}