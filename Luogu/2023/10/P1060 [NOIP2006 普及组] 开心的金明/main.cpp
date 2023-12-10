#include <bits/stdc++.h>

using namespace std;

int n, m, v[30], p[30], dp[30][30005];

void solve(){
	for(int i = 1; i <= m; i++){
		for(int j = 0; j <= n; j++){
			if(v[i] > j) dp[i][j] = dp[i - 1][j];
			else{
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i]] + p[i]);
			}
		}
	}
}

int main(int argc, char** argv) {
	cin >> n >> m;
	for(int i = 1; i <= m; i++){
		int pi;
		cin >> v[i] >> pi;
		p[i] = pi * v[i];
	}
	solve();
	cout << dp[m][n];
	return 0;
}
