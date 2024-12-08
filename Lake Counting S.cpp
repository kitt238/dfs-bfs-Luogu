#include<iostream>
#include<queue>
#define int long long																	
using namespace std;

typedef struct {
	int x, y;
}dot;

int n, m,ans=0;
char a[105][105];
int rec[105][105];
queue<dot>q;

void bfs(int x, int y) {
	rec[x][y] = 1;
	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			if (!i && !j)continue;
			if (a[x + i][y + j] == 'W' && !rec[x + i][y + j]) {
				rec[x + i][y + j] = 1;
				dot d0 = { x + i,y + j };
				q.push(d0);
			}
		}
	}
	if (!q.empty()) {
		dot q1 = q.front();
		q.pop();
		bfs(q1.x, q1.y);
	}
}

signed main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i][j] == 'W' && !rec[i][j]) {
				ans++;
				bfs(i, j);
			}
		}
	}
	cout << ans;
	return 0;
}