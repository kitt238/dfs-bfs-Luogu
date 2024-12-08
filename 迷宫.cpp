#include<iostream>
#define int long long																	
using namespace std;

int a[10][10];//ÕÏ°­
int rec[10][10];//±ê¼Ç
int n, m, t;
int sx, sy, fx, fy;
int ans = 0;

void dfs(int x, int y) {
	if (x == fx && y == fy) {
		ans++;
		rec[x][y] = 0;
		return;
	}
	if (!a[x][y + 1] && !rec[x][y + 1]) {
		rec[x][y + 1] = 1;
		dfs(x, y + 1);
		rec[x][y + 1] = 0;
	}
	if (!a[x+1][y] && !rec[x+1][y]) {
		rec[x+1][y] = 1;
		dfs(x+1, y);
		rec[x+1][y] = 0;
	}if (!a[x][y - 1] && !rec[x][y - 1]) {
		rec[x][y - 1] = 1;
		dfs(x, y - 1);
		rec[x][y - 1] = 0;
	}if (!a[x-1][y] && !rec[x-1][y]) {
		rec[x-1][y] = 1;
		dfs(x-1, y);
		rec[x-1][y] = 0;
	}
}

signed main() {
	cin >> n >> m >> t;
	cin >> sx >> sy >> fx >> fy;
	for (int i = 0; i <=max(n,m)+1; i++) {
		a[0][i] = 1;
		a[n + 1][i] = 1;
		a[i][0] = 1;
		a[i][m + 1] = 1;
	}//½¨Ç½
	for (int i = 0; i < t; i++) {
		int x, y;
		cin >> x >> y;
		a[x][y] = 1;
	}
	rec[sx][sy] = 1;
	dfs(sx, sy);
	cout << ans;
	return 0;
}