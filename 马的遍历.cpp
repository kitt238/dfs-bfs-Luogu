#include<iostream>
#include<queue>
#define int long long																	
using namespace std;

typedef struct {
	int x, y;
}dot;

queue<dot>q;

int a[405][405], n, m,xx,yy;
int dx[] = { 0,-2,-2,-1,-1,1,1,2,2 };
int dy[] = { 0,1,-1,2,-2,2,-2,1,-1 };//°ËÖÖ×ß·¨

void bfs(int x, int y,int step) {
	for (int i = 1; i <= 8; i++) {
		if (x + dx[i]<1 || x + dx[i]>n || y + dy[i]<1 || y + dy[i]>m) {
			continue;
		}
		if (!a[x + dx[i]][y + dy[i]]) {
			a[x + dx[i]][y + dy[i]] = step + 1;
			dot q0 = { x + dx[i], y + dy[i] };
			q.push(q0);
		}
	}
	if (!q.empty()) {
		dot q1 = q.front();
		q.pop();
		bfs(q1.x, q1.y,a[q1.x][q1.y]);
	}
}

signed main() {
	cin >> n >> m>>xx>>yy;
	bfs(xx, yy, 0);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (i == xx && j == yy)cout << 0 << ' ';
			else if (!a[i][j])cout << -1 << ' ';
			else cout << a[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}