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
vector<int> adj[N];
int32_t main(){
    	SKILLER;
    	#ifndef ONLINE_JUDGE
        freopen("inputf.in", "r", stdin);
    	//    freopen("outputf.in", "w", stdout);
    	#endif 
        int n; cin >> n;
      //  map<pair<int, int>, int> mp;
        for(int i = 0; i < n-1; i++){
        	int x, y; cin >> x >> y;
        	adj[x].pb(y);
        	adj[y].pb(x);
        }
       	vector<int> dp(n + 1, 0), sz(n + 1, 0);
       	function<void(int, int)> dfs1 = [&](int i, int p){
       		sz[i] = 1;
       		for(auto x:adj[i]){
       			if(x == p)
       				continue;
       			dfs1(x, i);
       			sz[i] += sz[x];
       		}
       	};
       	function<void(int, int)> dfs2 = [&](int i, int p){
       		dp[i] = sz[i];
       		for(auto x:adj[i]){
       			if(x == p)
       				continue;
       			dfs2(x, i);
       			dp[i] += dp[x];
       		}
       	};
       	int ans = 0;
       	function<void(int, int)> dfs3 = [&](int i, int p){
       		ans = max(ans, dp[i]);
       		for(auto x:adj[i]){
       			if(x == p)
       				continue;
       			dp[i] -= sz[x];
       			dp[i] -= dp[x];
       			sz[i] -= sz[x];
       			sz[x] += sz[i];
       			dp[x] += dp[i];
       			dp[x] += sz[i];
       			dfs3(x, i);
       			//cout << x;
       			dp[x] -= sz[i];
       			dp[x] -= dp[i];
       			sz[x] -= sz[i];
       			sz[i] += sz[x];
       			dp[i] += dp[x];
       			dp[i] += sz[x];
       		}
       	};
       	dfs1(1, 1);
       	dfs2(1, 1);
       	dfs3(1, 1);
       	cout << ans;
    	return 0;
}