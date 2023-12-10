#include <bits/stdc++.h>

using namespace std;

stack<int> S;

int main(int argc, char** argv) {
	string s;
	cin >> s;
	int n = 0;
	string num;
	for(auto it : s){
		if(it == '@'){
			break;
		}
		if(isdigit(it)){
			num += it;
			continue;
		}
		if(it == '.'){
			for(int i = 1; !num.empty(); i *= 10){
				n += i * (num.back() - '0');
				num.pop_back();
			}
			S.push(n);
			n = 0;
			string newstr;
			num = newstr;
		}
		if(it == '+'){
			int a, b;
			a = S.top();
			S.pop();
			b = S.top();
			S.pop();
			S.push(a + b);
		}
		if(it == '*'){
			int a, b;
			a = S.top();
			S.pop();
			b = S.top();
			S.pop();
			S.push(a * b);
		}
		if(it == '-'){
			int a, b;
			a = S.top();
			S.pop();
			b = S.top();
			S.pop();
			S.push(b - a);
		}
		if(it == '/'){
			int a, b;
			a = S.top();
			S.pop();
			b = S.top();
			S.pop();
			S.push(b / a);
		}
	}
	cout << S.top();
	return 0;
}
