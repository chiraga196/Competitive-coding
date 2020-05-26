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
const   int N = 1e5+5, Mod = 1e9 + 7;
int n, k; 
string s;
vector<string> v(N);
int32_t main(){
    	SKILLER;
    	#ifndef ONLINE_JUDGE
        freopen("inputf.in", "r", stdin);
    	//    freopen("outputf.in", "w", stdout);
    	#endif 
    	cin >> n >> k;
    	cin >> s;
    	int mx = 0;
    	for(int i = 1; i <= n; i++){
    		cin >> v[i];
    		mx = max(mx, v[i].length()*1LL);
    	}
    	vector<int> ans(n + 1, 0);
    	vector<vector<int>> pre(26), post(26);
    	for(int i = 0; i < 26; i++){
    			if(s[0] - 'a' == i)
    				pre[i].pb(0);
    			else pre[i].pb(1e10);
    			for(int k1 = 1; k1 < s.length(); k1++){
    				if(s[k1] - 'a' == i){
    					pre[i].pb(0);
    				}
    				else{
    					pre[i].pb(pre[i].back() + 1);
    				}
    			}
    			while(pre[i].size() < mx)
    				pre[i].pb(pre[i].back() + 1);
    	}
    	for(int i = 0; i < 26; i++){
    			if(s[k - 1] - 'a' == i)
    				post[i].pb(0);
    			else post[i].pb(1e10);
    			int k1 = s.length();
    			k1 -= 2;
    			for(; k1 >= 0; k1--){
    				if(s[k1] - 'a' == i){
    					post[i].pb(0);
    				}
    				else{
    					post[i].pb(post[i].back() + 1);
    				}
    			}
    			reverse(all(post[i]));
    		
    	}
    	for(int i = 1; i <= n; i++){
    		ans[i] = 0;
    		int y = v[i].length();
    		for(int j = 0; j < v[i].length(); j++){
    			int prx;
    			int c = v[i][j] - 'a';
    			if(pre[c][j] < 1e7)
    				prx = pre[c][j];
    			else prx = 1e15;
    			int pst;
    			if(post[c].size() <= j)
    				pst = 1e15;
    			else{
    				if(post[c][j] < 1e7)
    					pst = post[c][j];
    				else pst = y;
    			}
    			if(prx > 1e10 && pst > 1e10)
    				ans[i] += y;
    			else if(prx > 1e10)
    				ans[i] += pst;
    			else if(pst > 1e10)
    				ans[i] += prx;
    			else
    				ans[i] += min(prx, pst);
    		}
    	}
    	for(int i = 1; i <= n; i++)
    		cout << ans[i] <<"\n";
    	return 0;
}