#include <bits/stdc++.h>

using namespace std;

int xl, xu, yl, yu;
int64_t mul;

int main(int argc, char *argv[]) {
	cin >> xl >> xu >> yl >> yu;
	mul = (int64_t) xu * (int64_t) yu;
	if (mul > 2147483647ll) {
		cout << "long long int";
	}
	else {
		cout << "int";
	}
	return 0;
}