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
    	// auto start=std::chrono::steady_clock::now();
        int n; cin >> n;
        vector<int> v(n);
        for(auto &x:v)
        	cin >> x;
       	vector<int> seive(2e7 + 10, 0);
       	for(ll i = 2; i <= 20000004; i++)
       	        seive[i] = i;
       	for(ll i = 2; i <= 20000004; i += 2)
       	        seive[i] = 2;
       	for(ll i = 3; i * i < 20000004; i += 2) 
       	{ 
       	        if(seive[i] == i) 
       	        { 
       	            for(ll j = i * i; j < 20000004; j += i) 
       	                if(seive[j] == j) 
       	                    seive[j] = i; 
       	        } 
       	    } 
        vector<int> dp(2e7 + 10, 0);
        for(int i = 0; i < n; i++){
        	int x = v[i];
        	map<int, int> mp;
        	while(x > 1){
        		mp[seive[x]] = 1;
        		x /= seive[x];
        	}
        	for(auto x:mp){
        		if(x.ss == 1){
        			dp[x.ff]++;
        		}
        	}
        }
        dp[1] = n;
        for(int i = 2; i <= 2e7 + 10; i++){
        	dp[i] += dp[i-1];
        }
        int m; cin >> m;
        while(m--){
        	int a, b; cin >> a >> b;
        	b = min(20000005 * 1LL, b);
        	a = min(20000006*1LL, a);
        	cout << dp[b] - dp[max(0LL, a-1)] <<"\n";
        }
    	return 0;
}
