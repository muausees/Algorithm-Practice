#include <bits/stdc++.h>

using namespace std;

int n;
string s;

void dfs(int num, int pre, bool first){
	if(num == 0){
		cout << s << endl;
	}
	if(num != 0 && !first){
		s.push_back('+');
	}
	int numClone = num;
	if(first){
		numClone -= 1;
	}
	for(int i = pre; i <= numClone; i++){
		s.push_back(i + '0');
		dfs(num - i, i, false);
		s.pop_back();
	}
	if(num != 0) s.pop_back();
}

int main(int argc, char** argv) {
	cin >> n;
	dfs(n, 1, true);
	return 0;
}
