#include<iostream>
#define int long long																	
using namespace std;

int n, s[13], b[13];
int ans = 999999999999;

void dfs(int i, int acid, int bitter) {
	if (i > n) {
		if (acid != 1 && bitter != 0) {
			ans = min(ans, abs(acid - bitter));
		}
		return;
	}
	dfs(i + 1, acid, bitter);
	dfs(i + 1, acid * s[i + 1], bitter + b[i + 1]);
}

signed main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> s[i] >> b[i];
	}
	dfs(0, 1, 0);
	cout << ans;
	return 0;
}