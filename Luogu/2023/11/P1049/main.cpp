#include <bits/stdc++.h>

using namespace std;

int V, n;
int T[35], dp[20050];
//dp数组存背包里装的物品体积

int main(int argc, char** argv) {
	cin >> V >> n;
	for(int i = 1; i <= n; i++) {
		cin >> T[i];
	}
	for(int i = 1; i <= n; i++) {
		for(int j = V; j >= T[i]; j--){ //滚动数组优化
			dp[j] = max(dp[j], dp[j - T[i]] + T[i]); 
		}
	}
	cout << V - dp[V];
	return 0;
}
