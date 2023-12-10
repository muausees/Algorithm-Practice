#include <bits/stdc++.h>

using namespace std;

int n, M, T, m[105], t[105], dp[105][205][205];

void solve(){
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= M; j++){
			for(int k = 0; k <= T; k++){
				if(m[i] > j || t[i] > k) dp[i][j][k] = dp[i - 1][j][k];
				else{
					dp[i][j][k] = max(dp[i - 1][j][k], dp[i - 1][j - m[i]][k - t[i]] + 1);
				}
			}
		}
	}
}

int main(int argc, char** argv) {
	cin >> n >> M >> T;
	for(int i = 1; i <= n; i++){
		cin >> m[i] >> t[i];
	}
	solve();
	cout << dp[n][M][T];
	return 0;
}
