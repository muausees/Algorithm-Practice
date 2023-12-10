#include <bits/stdc++.h>

using namespace std;

int n, sum = 0;

int main(int argc, char** argv) {
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		int m;
		scanf("%d", &m);
		sum ^= m;
	}
	printf("%d", sum);
	return 0;
}
