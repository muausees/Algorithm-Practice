#include <bits/stdc++.h>

using namespace std;

int n, k;
int out = 0;

int digit(int num){
	return num % 10;
}

bool isInt(double x){
	return abs(x - (int)x) < 1e-9;
}

int main(int argc, char *argv[]) {
	cin >> n >> k;
	for(int x = n; x < n + k; x += 1) {
		if(isInt((double)(x % k) / n)){
			int xclone = x;
			while(xclone <= pow(n, n)){
				if(digit(xclone) == n) out++;
				xclone += k;
			}
		}
	}
	cout << out;
	return 0;
}