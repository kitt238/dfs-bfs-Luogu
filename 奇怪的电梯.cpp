#include<iostream>
#include<queue>
#define int long long		
#define INF 0x7fffffff
using namespace std;

typedef struct {
	int v;
	int level;
}element;

int n, a, b,min=INF,ans=0;
int rac[250][250];//邻接矩阵
int found[250];//已发现标记

queue<element>q;//bfs

int visit(element e0) {
	if (e0.v == b) {
		return e0.level;
	}
	for (int i = 1; i <= n; i++) {
		if (rac[e0.v][i] && !found[i]) {
			element e = { i,e0.level + 1 };
			found[i] = 1;
			q.push(e);
		}
	}
	if (!q.empty()) {
		element e1 = q.front();
		q.pop();
		return visit(e1);
	}
	else return -1;
}

signed main() {
	cin >> n>>a>>b;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		if (i + x <= n)rac[i][i + x] = 1;
		if (i - x >= 1)rac[i][i - x] = 1;
	}
	element e0 = { a,0 };
	cout<<visit(e0);
	return 0;
}