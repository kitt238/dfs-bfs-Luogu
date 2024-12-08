#include<iostream>
#define int long long																	
using namespace std;

int a[15][15],n;//建图
int road[15];
int ans = 0;

void set(int x, int y,int set) {
	for (int i = y+1; i <= n; i++) {
		a[x][i] += set;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = y+1; j <= n; j++) {
			if ((i - j == x-y) || (i + j == x+y)) {
				a[i][j] += set;
			}
		}
	}
}//设置对角线

void visit(int x, int y) {
	if (!x && !y)goto here;
	if (y == n) {
		ans++;
		if (ans <= 3) {
			for (int i = 1; i <= n; i++) {
				cout << road[i] << ' ';
			}
			cout << '\n';
		}
		return;
	}
	set(x, y, 1);
	here:
	for (int i = 1; i <= n; i++) {
		if (!a[i][y + 1]) {
			road[y+1] = i;
			visit(i, y + 1);
		}
	}
	set(x, y, -1);
}

signed main() {
	cin >> n;
	visit(0, 0);
	cout << ans;
	return 0;
}
//备注：时间复杂度为n^n的屎山玩意