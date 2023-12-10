#include <bits/stdc++.h>

using namespace std;

int vTable[6] = {1, 2, 3, 5, 10, 20};
int v[2010];
int k = 1;
int total = 0;
int dp[2010];
int ans = 0;

int main(int argc, char** argv) {
	for (int i = 0; i <= 5; i++) {
		int a;
		cin >> a;
		total += a * vTable[i];
		for (int j = 1; j <= a; j++) {
			v[k++] = vTable[i];
		}
	}
	k--;
	dp[0] = 1;
	for (int i = 1; i <= k; i++) {
		for (int j = total; j >= v[i]; j--) {
			dp[j] += dp[j - v[i]];
		}
	}
	for(int i = 1; i <= total; i++){
		if(dp[i]) ans++;
	}
	cout << "Total=" << ans;
	return 0;
}
