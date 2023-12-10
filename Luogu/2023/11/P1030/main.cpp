#include <bits/stdc++.h>

using namespace std;

string inOrder, postOrder;

void solve(string in, string post) {
	if (in.size() > 0) {
		char ch = post[post.size() - 1];
		cout << ch;
		int po = in.find(ch);
		solve(in.substr(0, po), post.substr(0, po));
		solve(in.substr(po + 1), post.substr(po, in.size() - po - 1));
	}
}

int main(int argc, char** argv) {
	cin >> inOrder >> postOrder;
	solve(inOrder, postOrder);
	return 0;
}
