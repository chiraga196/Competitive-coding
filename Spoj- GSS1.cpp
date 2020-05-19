#include<bits/stdc++.h>
using namespace std; 
vector<int> v;
struct STree{
	int left;
	int right;
	int tot;
	int best;
};
STree *st = new STree[300000]; 
void build(int si, int l, int r){
	if(l == r){
		st[si].left = v[l];
		st[si].right = v[l];
		st[si].tot = v[l];
		st[si].best = v[l];
		return;
	}
	int mid = l + r;
	mid >>= 1;
	build(2*si, l, mid);
	build(2*si + 1, mid + 1, r);
	st[si].left = max(st[2*si].left, st[2*si].tot + st[2*si + 1].left);
	st[si].right = max(st[2*si+1].right, st[2*si + 1].tot + st[2*si].right);
	st[si].tot = st[2*si].tot + st[2*si + 1].tot;
	st[si].best = max(st[2*si].best, max(st[2*si + 1].best, st[2*si].right + st[2*si + 1].left));
}
int inf = -1e7;
STree query(int si, int a, int b, int l, int r){
	if(l > b || r < a){
		return (STree){
			inf,
			inf,
			0,
			inf
		};
	}
	if(l >= a && r <= b){
		return st[si];
	}
	int mid = l + r;
	mid >>= 1;
	STree p1 = query(2*si, a, b, l, mid), p2 = query(2*si + 1, a, b, mid + 1, r), res;
	res.best = max(p1.best, max(p2.best, p1.right + p2.left));
	res.left = max(p1.left, p1.tot + p2.left);
	res.right = max(p2.right, p2.tot + p1.right);
	res.tot = p1.tot + p2.tot;
	return res;
}

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	freopen("inputf.in", "r", stdin);
	int n; cin >> n;
	v.resize(n+1);
	for(int i = 1; i <= n; i++)
		cin >> v[i];

	build(1, 1, n);
	int qury; cin >> qury;
	while(qury--){
		int a, b; cin >> a >> b;
		if(a > b)
			swap(a, b);
		STree best = query(1, a, b, 1, n);
		cout << max(best.best, max(best.left, max(best.right, best.tot))) <<"\n";
	}
}