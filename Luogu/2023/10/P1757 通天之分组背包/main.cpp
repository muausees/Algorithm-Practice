#include <bits/stdc++.h>

using namespace std;

int m, n, t = 0, a[100005], b[100005], c[100005], g[10005][10005], dp[10005];

void solve(){
	for(int i = 1; i <= t; i++){
		for(int j = m; j >= 0; j--){
			for(int k = 1; k <= c[i]; k++){
				if(a[g[i][k]] <= j){
					dp[j] = max(dp[j], dp[j - a[g[i][k]]] + b[g[i][k]]);
				}
			}
		}
	}
}

int main(int argc, char** argv) {
	cin >> m >> n;
	for(int i = 1; i <= n; i++){
		int x = 0;
		cin >> a[i] >> b[i] >> x;
		t = max(t, x);
		c[x]++;
		g[x][c[x]] = i;
	}
	solve();
	cout << dp[m];
	return 0;
}
