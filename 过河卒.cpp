#include<iostream>
#include<cstring>
#define INF 0x7fffffff
#define int long long																	
using namespace std;

int rec[25][25];
int n, m;
int xm, ym;
int dx[] = { -2,-2,-1,-1,0,1,1,2,2 };
int dy[] = { 1,-1,2,-2,0,2,-2,1,-1 };

int dp(int x, int y) {
	if (rec[x][y]!=-1)return rec[x][y];
	rec[x][y]= dp(x - 1, y) + dp(x, y - 1);
	return rec[x][y];
}

void solve() {
	memset(rec, -1, sizeof(rec));
	cin >> n >> m >> xm >> ym;
	for (int i = 0; i <= max(n,m); i++) {
		rec[0][i] = 1;
		rec[i][0] = 1;
	}
	for (int i = 0; i < 9; i++) {
		int rx = xm + dx[i];
		int ry = ym + dy[i];
		if (rx > n || rx<0 || ry>m || ry < 0)continue;
		rec[rx][ry] = 0;
		if (rx == 0) {
			for (int i = ry; i <= m; i++)
				rec[rx][i] = 0;
		}
		if (ry == 0) {
			for (int i = rx; i <= n; i++)
				rec[i][ry] = 0;
		}
	}
	cout << dp(n, m);
}

signed main() {
	solve();
	return 0;
}