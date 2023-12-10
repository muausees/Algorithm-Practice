//10
#include <bits/stdc++.h>

using namespace std;

int table[26] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26};
int sum = 0;

int main(int argc, char** argv) {
	string word;
	cin >> word;
	int l = word.length();
	for(auto i : word){
		sum += table[i - 97] * pow(26, l - 1);
		l--;
	}
	cout << sum;
	return 0;
}
