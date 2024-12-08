#include<iostream>
#include<queue>
#define int long long																	
using namespace std;

typedef struct {
	int x;
	int y;
}dot;

int a[35][35],n;//建图
int rec[35][35];//记录
queue<dot>q;//bfs

void clean() {
	for (int i = 1; i <=n; i++) {
		for (int j = 1; j <=n; j++) {
			if (rec[i][j] == 1) {
				rec[i][j] = 2;
			}
		}
	}
}

int visit(int x, int y,int hit) {
	rec[x][y] = 1;
	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			if (!i && !j)continue;
			if (!i || !j) {
				if (!a[x + i][y + j] && !rec[x + i][y + j]) {
					rec[x + i][y + j] = 1;
					dot d = { x + i,y + j };
					q.push(d);
				}
				else if (a[x + i][y + j] == -1) {
					hit = 1;
				}
			}
		}
	}
	if (!q.empty()) {
		dot d0 = q.front();
		q.pop();
		return visit(d0.x, d0.y,hit);
	}
	else return hit;
}

void print_colour() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (rec[i][j]==1) {
				cout << 2 << ' ';
			}
			else if (a[i][j]) {
				cout << 1 << ' ';
			}
			else {
				cout << 0 << ' ';
			}
		}
		cout << '\n';
	}
}

signed main() {
	cin >> n;
	for (int i = 0; i <= n + 1; i++) {
		a[0][i] = -1;
		a[i][0] = -1;
		a[n + 1][i] = -1;
		a[i][n + 1] = -1;
	}//建墙
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}//建圈
	int i, j;
	for (i = 1; i <= n; i++) {
		for ( j = 1; j <= n; j++) {
			if (!a[i][j] && !rec[i][j]) {
				goto there;
			}
		}
	}
	there:
	while (visit(i, j, 0)) {
		clean();
		for (i=1; i <= n; i++) {
			for (j=1; j <= n; j++) {
				if (!a[i][j] && !rec[i][j]) {
					goto here;
				}
			}
		}
	here:;
	}
	print_colour();
	return 0;
}
//我勒个豆豆