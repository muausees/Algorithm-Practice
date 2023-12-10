#include <bits/stdc++.h>

using namespace std;

int T, N, M;
int p[105][105];
int dp[10005];

int main(int argc, char *argv[]) {
	cin >> T >> N >> M;
	for (int i = 1; i <= T; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> p[i][j];
		}
	}
	for (int i = 1; i <= T; i++) {
		memset(dp, 0, sizeof dp);
		for (int j = 1; j <= N; j++) {
			for (int k = p[i][j]; k <= M; k++) {
				dp[k] = max(dp[k], dp[k - p[i][j]] + p[i + 1][j] - p[i][j]);
			}
		}
		M += dp[M];
	}
	cout << M;
	return 0;
}