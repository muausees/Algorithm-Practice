#include <bits/stdc++.h>

using namespace std;

int n;
int M[150][150];
int degree[150];
stack<char> S;

void eular(int u){
	for(int v = 0; v < 150; v++){
		if(M[u][v]){
			M[u][v] = 0;
			M[v][u] = 0;
			eular(v);
		}
	}
	S.push((char)u);
}

int main(int argc, char** argv) {
	cin >> n;
	for(int i = 0; i < n; i++){
		char u, v;
		cin >> u >> v;
		degree[(int)u]++;
		degree[(int)v]++;
		M[(int)u][(int)v] = 1;
		M[(int)v][(int)u] = 1;
	}
	int a = 0;
	for(int i = 0; i < 150; i++){
		if(degree[i] % 2) a++;
	}
	if(a != 0 && a != 2){
		cout << "No Solution";
		return 0;
	}
	else for(int i = 0; i < 150; i++){
		if(degree[i] != 0) {
			eular(i);
			while(!S.empty()){
				cout << S.top();
				S.pop();
			}
			return 0;
		}
	}
	return 0;
}
