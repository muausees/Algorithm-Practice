#include <bits/stdc++.h>

using namespace std;

void tree(string s) {
	if (s.length() > 1) {
		tree(s.substr(0, s.length() / 2));
		tree(s.substr(s.length() / 2, s.length()));
	}
	if (s == string(s.length(), '0')) cout << 'B';
	else if (s == string(s.length(), '1')) cout << 'I';
	else cout << 'F';
}

int main() {
	int none;
	cin >> none;
	string str;
	cin >> str;
	tree(str);
	return 0;
}
