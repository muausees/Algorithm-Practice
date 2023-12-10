//AC
#include <bits/stdc++.h>

using namespace std;

int N, X;
int Sum = 0;

int main(int argc, char* argv[]) {
	cin >> N >> X;
	for (int i = 0; i < N; i++) {
		int p1, p2;
		cin >> p1 >> p2;
		if (abs(p1 - p2) <= X) {
			Sum += max(p1, p2);
		} else {
			int p3;
			cin >> p3;
			Sum += p3;
		}
	}
	cout << Sum;
	return 0;
}
