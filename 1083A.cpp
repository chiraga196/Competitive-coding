//Hey u r far away to know this
#include <bits/stdc++.h>
using namespace std;
#define     ff      	    	first
#define     pb 	         	push_back
#define     ss          		second
#define     ll      	    	long long
#define     MAX  	       	5000
#define     mpi         		map<int, int>
#define     mpll        		map<ll, ll>
#define     pll         		pair<ll, ll>
#define     plld        		pair<ll, double>
#define     SKILLER     		ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define     vi          		std::vector<int>
#define     vll         		std::vector<ll>
#define     vs          		std::vector<string>
#define     vvi         		std::vector<std::vector<int>>
#define     vvll        		std::vector<std::vector<ll>>
#define     all(v)      		v.begin(), v.end()
#define     allr(v)      		v.rbegin(), v.rend()
#define     loop(i, a, b) 	for(int i = a; i < b; i++)
#define 	  debug(x) 		cout << x <<" " <<"\n";
#define 	  debug1(x, y) 	cout << x << " " << y  << "\n";
#define 	  debug2(x, y, z) 	cout << x << " " << y << " " << z<<"\n";
#define 	  int 			ll
const   int N = 1e6+5, Mod = 1e9 + 7;
int32_t main(){
    	SKILLER;
    	#ifndef ONLINE_JUDGE
        freopen("inputf.in", "r", stdin);
    	//    freopen("outputf.in", "w", stdout);
    	#endif 
        int n; cin >> n;
        vector<int> v(n + 1);
        for(int i = 0; i < n; i++)
        	cin >> v[i+1];
        vector<pair<int, int >> adj[n+1];
        for(int i = 0; i < n-1; i++){
        	int a, b, c; cin >> a >> b >> c;
        	adj[a].pb({b, c});
        	adj[b].pb({a, c});
        }
        //vector<int> dp(n+1, 0);
        int ans = 0;
        function<int(int, int)> dfs1 = [&](int i, int par){
        	int mx1 = 0, mx2 = 0;
        	ans = max(ans, v[i]);
        	for(auto x:adj[i]){
        		if(x.ff == par)
        			continue;
        		int mt = dfs1(x.ff, i) - x.ss;
        		if(mx1 < mt){
        			mx2 = mx1;
        			mx1 = mt;
        		}
        		else if(mx2 < mt)
        			mx2 = mt;
        	}
        	ans = max(ans, mx1 + mx2 + v[i]);
        	return mx1 + v[i];
        };
    	ans = 0;
        dfs1(1, 1);
        cout << ans;
    	return 0;
}