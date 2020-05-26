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
const   int N = 2e5+5, Mod = 1e9 + 7, k = 22;
int lca[N][22];
int dist[N][22];
int lv[N];
vector<pair<int, int>> adj[N];
vector<int> v(N);
void dfs(int u, int v){
	for(auto x:adj[u]){
		if(x.ff == v)
			continue;
		dist[x.ff][0] = x.ss;
		lv[x.ff] = lv[u] + 1;
		lca[x.ff][0] = u;
		dfs(x.ff, u);
	}
}
int walk(int a, int val){
	int x = a;
	for(int i = k - 1; i >= 0; i--){
		if(lca[x][i] != -1){
			if(dist[x][i] <= val){
				val -= dist[x][i];
				x = lca[x][i];
			}
		}
	}
	return x;
}
vector<int> ans;
vector<int> wt(N, 0);
int dfs2(int u, int v){
	int cst = 0;
	for(auto &x:adj[u]){
		if(x.ff != v){
			cst += dfs2(x.ff, u);
		}
	}
	//cout << cst <<" " << wt[u] <<"\n";
	cst += wt[u];
	ans[u] = cst;
	return cst;
}
int32_t main(){
    	SKILLER;
    	#ifndef ONLINE_JUDGE
        freopen("inputf.in", "r", stdin);
    	//    freopen("outputf.in", "w", stdout);
    	#endif 
        memset(lca, -1, sizeof(lca));
        memset(dist, 0, sizeof(dist));
        int n; cin >> n;
        for(int i = 1; i <= n; i++)
        	cin >> v[i];
        for(int i = 2; i <= n; i++){
        	int a, b; cin >> a >> b;
        	adj[i].pb({a, b});
        	adj[a].pb({i, b});
        }
        dfs(1, 1);
        for(int i = 1; i < k; i++){
        	for(int j = 1; j <= n; j++){
        		if(lca[j][i - 1] != -1){
        			lca[j][i] = lca[lca[j][i - 1]][i - 1];
        			dist[j][i] = dist[lca[j][i - 1]][i - 1] + dist[j][i - 1];
        		}
        	}
        }
        
        for(int i = 1; i <= n; i++){
        	int r = walk(i, v[i]);
        	if(r == 1 && i != 1)
        		wt[lca[i][0]] += 1;
        	else if (r != i){
        		wt[lca[r][0]] -= 1;
        		wt[lca[i][0]] += 1;
        	}
        }
        ans.resize(n + 1, 0);
        int x = dfs2(1, 1);
        for(int i = 1; i <= n; i++)
        	cout << ans[i] <<" ";
    	return 0;
}