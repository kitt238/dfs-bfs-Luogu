#include<iostream>
#include<queue>
#include<cstdio>																
using namespace std;

typedef struct {
	int x;
	int y;
}dot;

int ans = 0;
int dx[] = { 0,-1,1,0,0 };
int dy[] = { 0,0,0,-1,1 };
int a[105][105];//记录是否有细胞
int b[105][105];//记录是否被探索过
queue<dot>q;

void visit(int x, int y) {
	b[x][y] = 1;
	for (int i = 1; i <= 4; i++) {
		if (a[x + dx[i]][y + dy[i]]&&!b[x + dx[i]][y + dy[i]]) {
			b[x + dx[i]][y + dy[i]] = 1;
			dot q0 = { x + dx[i],y + dy[i] };
			q.push(q0);
		}
	}
	if (!q.empty()) {
		dot q1 = q.front();
		q.pop();
		visit(q1.x, q1.y);
	}
}

signed main() {
	int n, m;
	cin >> n >> m;
	//getchar();//除换行
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			char c;
			cin >> c;
			a[i][j] = c - '0';
		}
		//getchar();//除换行
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i][j] && !b[i][j]) {
				visit(i, j);
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}