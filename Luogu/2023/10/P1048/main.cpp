#include <bits/stdc++.h>

using namespace std;

int T, M, t[105], v[105], dp[105][1005];

void solve(){
	for(int i = 1; i <= M; i++){
		for(int j = 0; j <= T; j++){
			if(t[i] > j) dp[i][j] = dp[i - 1][j];
			else{
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - t[i]] + v[i]); //装或不装
			}
		}
	}
}

int main(int argc, char** argv) {
	cin >> T >> M;
	for(int i = 1; i <= M; i++){
		cin >> t[i] >> v[i];
	}
	memset(dp, 0, sizeof dp);
	solve();
	cout << dp[M][T];
	return 0;
}
