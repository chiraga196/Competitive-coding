#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define ff first
#define ss second
int32_t main() {
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);cout.tie(NULL);
		//freopen("inputf.in", "r", stdin);
		int n; cin >> n;
		vector<pair<int, pair<int, int> > > v(n);
		for(int i = 0; i < n; i++){
			cin >> v[i].ss.ff;
			cin >> v[i].ss.ss;
			v[i].ff = v[i].ss.ff - v[i].ss.ss;
		}
		sort(v.rbegin(), v.rend());
		int ans = 0;
		for(int i = 0; i < n; i++){
			ans += (i)*v[i].ss.ff + (n - i - 1)*v[i].ss.ss;
		}
		cout << ans <<"\n";
}