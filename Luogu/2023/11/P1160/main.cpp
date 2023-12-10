#include <bits/stdc++.h>

using namespace std;

int n, m, frontid;

class node{
public:
	int flag, preid, nextid;
	node(){
		flag = preid = nextid = 0;
	}
}l[100005];

int main(int argc, char** argv) {
	cin >> n;
	frontid = 1;
	l[1].flag = 1;
	for(int i = 2; i <= n; i++){
		l[i].flag = 1;
		int k, p;
		cin >> k >> p;
		if(p == 1){
			if(l[k].nextid == 0){
				l[k].nextid = i;
				l[i].preid = k;
			}
			else{
				l[l[k].nextid].preid = i;
				l[i].nextid = l[k].nextid;
				l[i].preid = k;
				l[k].nextid = i;
			}
		}
		else{
			if(l[k].preid == 0){
				frontid = i;
				l[k].preid = i;
				l[i].nextid = k;
			}
			else{
				l[l[k].preid].nextid = i;
				l[i].preid = l[k].preid;
				l[i].nextid = k;
				l[k].preid = i;
			}
		}
	}
	cin >> m;
	for(int i = 1; i <= m; i++){
		int x;
		cin >> x;
		if(x == frontid){
			frontid = l[x].nextid;
		}
		l[l[x].preid].nextid = l[x].nextid;
		l[l[x].nextid].preid = l[x].preid;
		l[x].nextid = l[x].preid = 0;
		l[x].flag = 0;
	}
	int m = frontid;
	while(l[m].nextid != 0){
		cout << m << ' ';
		m = l[m].nextid;
	}
	cout << m;
	return 0;
}
