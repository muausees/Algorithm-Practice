#include <bits/stdc++.h>

using namespace std;

int N, C, x[100005];

bool cmp(int a, int b){
	return a < b;
}

bool check(int num){
	int a = 0, b = x[1];
	for(int i = 2; i <= N; i++){
		if(x[i] - b >= num){
			a++;
			b = x[i];
		}
		if(a >= C) return true;
	}
	if(a + 1 < C) return false;
	return true;
}

int binary(int a){
	int left = 1;
	int right = a;
	int ans = 0;
	while(right >= left){
		int mid = (left + right) / 2;
		if(check(mid)){
			ans = max(ans, mid);
			left = mid + 1;
		}
		else{
			right = mid - 1;
		}
	}
	return ans;
}

int main(){
	//freopen("milk.in", "r", stdin);
	//freopen("milk.out", "w", stdout);
	cin >> N >> C;
	int mincha = 50000005;
	for(int i = 1; i <= N; i++){
		cin >> x[i];
		if(i >= 2){
			mincha = min(mincha, x[i] - x[i - 1]);
		}
	}
	sort(x + 1, x + 1 + N, cmp);
	int out = binary(x[N] - x[1]);
	cout << out;
	return 0;
}
