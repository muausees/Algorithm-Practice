#include <bits/stdc++.h>

using namespace std;

int n, m;
array<int, (uint32_t)2e6> a;

int main(int argc, char** argv) {
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	for(int i = 1; i <= m; i++){
		int pos;
		cin >> pos;
		printf("%d\n", a[pos]);
	}
	return 0;
}
