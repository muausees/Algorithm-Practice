//AC
#include <bits/stdc++.h>

using namespace std;

int64_t n, x;
array<int64_t, 1005> lose, win, use;
array<array<int64_t, 1005>, 1005> dp;

int main(int argc, char** argv) {
	cin >> n >> x;
	for(int i = 1; i <= n; i++){
		cin >> lose[i] >> win[i] >> use[i];
	}
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= x; j++){
			if(j >= use[i]){
				dp[i][j] = max(dp[i - 1][j] + lose[i], dp[i - 1][j - use[i]] + win[i]);
			}
			else{
				dp[i][j] = dp[i - 1][j] + lose[i];
			}
		}
	}
	cout << 5 * dp[n][x];
	return 0;
}
