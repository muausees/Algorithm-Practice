#include <bits/stdc++.h>

using namespace std;

class node{
public:
	int data;
	int id;
}a[2000005];

int n, m;
deque<node> D;

int main(int argc, char** argv) {
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		a[i].id = i;
		scanf("%d", &a[i].data);
	}
	cout << 0 << endl;
	for(int i = 2; i <= n; i++){
		if(i > m){
			while(!D.empty() && i - D.front().id > m){
				D.pop_front();
			}
		}
		while(!D.empty() && D.back().data > a[i - 1].data){
			D.pop_back();
		}
		D.push_back(a[i - 1]);
		printf("%d\n", D.front().data);
	}
	return 0;
}
