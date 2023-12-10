#include <bits/stdc++.h>

using namespace std;

int n;
uint64_t x;

int main(int argc, char* argv[]) {
    cin >> n;
	cin >> x;
	for(int i = 2; i <= n; i++){
		uint64_t input;
		cin >> input;
		x ^= input;
	}
	cout << x << " 0";
    return 0;
}