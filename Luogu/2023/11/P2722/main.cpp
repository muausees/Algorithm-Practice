#include <bits/stdc++.h>

using namespace std;

int m, n;
int p[10005], t[10005];
int64_t dp[10005];

int main(int argc, char** argv) {
	cin >> m >> n;
	for(int i = 1; i <= n; i++){
		cin >> p[i] >> t[i];
	}
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= m; j++){
			if(j >= t[i]){
				dp[j] = max(dp[j], dp[j - t[i]] + p[i]);
			}
		}
	}
	cout << dp[m];
	return 0;
}
