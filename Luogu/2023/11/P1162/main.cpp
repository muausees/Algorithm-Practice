#include <bits/stdc++.h>

using namespace std;

const array<int, 4> dx = {0, -1, 1, 0}, dy = {-1, 0, 0, 1};
int n;
array<array<int, 35>, 35> a, vis;

void dfs(int xt, int yt){
	vis[xt][yt] = 1;
	a[xt][yt] = 2;
	for(int i = 0; i < 4; i++){
		int xx = xt + dx[i], yy = yt + dy[i];
		if(xx < 0 || xx > n + 1 || yy < 0 || yy > n + 1 || vis[xx][yy] || a[xx][yy] == 1){
			continue;
		}
		dfs(xx, yy);
	}
}

int main(int argc, char** argv) {
	cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <=n; j++){
			cin >> a[i][j];
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cout << 2 - a[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}
