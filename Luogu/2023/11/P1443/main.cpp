#include <bits/stdc++.h>

using namespace std;

int n, m, x, y;
const array<int, 8> dx = {-2, -2, -1, -1, 1, 1, 2, 2};
const array<int, 8> dy = {-1, 1, -2, 2, -2, 2, -1, 1};
array<array<int, 405>, 405> a, vis;

//void dfs(int xt, int yt, int deepth){
//	a[xt][yt] = min(deepth, a[xt][yt]);
//	vis[xt][yt] = 1;
//	int xO = xt - 2, xT = xt - 1, xTh = xt + 1, xF = xt + 2;
//	int yO = yt - 2, yT = yt - 1, yTh = yt + 1, yF = yt + 2;
//	if(xO >= 1 && yT >= 1 && xO <= n && yT <= m && vis[xO][yT] == 0){
//		dfs(xO, yT, deepth + 1);
//	}
//	if(xO >= 1 && yTh >= 1 && xO <= n && yTh <= m && vis[xO][yTh] == 0){
//		dfs(xO, yTh, deepth + 1);
//	}
//	if(xT >= 1 && yO >= 1 && xT <= n && yO <= m && vis[xT][yO] == 0){
//		dfs(xT, yO, deepth + 1);
//	}
//	if(xT >= 1 && yF >= 1 && xT <= n && yF <= m && vis[xT][yF] == 0){
//		dfs(xt, yF, deepth + 1);
//	}
//	if(xTh >= 1 && yO >= 1 && xTh <= n && yO <= m && vis[xTh][yO] == 0){
//		dfs(xTh, yO, deepth + 1);
//	}
//	if(xTh >= 1 && yF >= 1 && xTh <= n && yF <= m && vis[xTh][yF] == 0){
//		dfs(xTh, yF, deepth + 1);
//	}
//	if(xF >= 1 && yT >= 1 && xF <= n && yT <= m && vis[xF][yT] == 0){
//		dfs(xF, yT, deepth + 1);
//	}
//	if(xF >= 1 && yTh >= 1 && xF <= n && yTh <= m && vis[xF][yTh] == 0){
//		dfs(xF, yTh, deepth + 1);
//	}
//	vis[xt][yt] = 0;
//}

void bfs(int xt, int yt){
	queue<pair<int, int>> Q;
	Q.push(make_pair(xt, yt));
	while(!Q.empty()){
		int xn = Q.front().first;
		int yn = Q.front().second;
		Q.pop();
		for(int i = 0; i < 8; i++){
			int u = xn + dx[i], v = yn + dy[i];
			if(u < 1 || u > n || v < 1 || v > m || vis[u][v]){
				continue;
			}
			vis[u][v] = 1;
			Q.push(make_pair(u, v));
			a[u][v] = a[xn][yn] + 1;
		}
	}
}

int main(int argc, char** argv) {
	cin >> n >> m >> x >> y;
	array<int, 405> temp;
	temp.fill(-1);
	a.fill(temp);
	vis[x][y] = 1;
	a[x][y] = 0;
	bfs(x, y);
	for(int i = 1; i <= n ; i++){
		for(int j = 1; j <= m; j++){
			cout << a[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}
