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
int n, m, k;
int x1, s;
pair<int, int> a[200005], b[200005];
int32_t main(){
    	SKILLER;
    	#ifndef ONLINE_JUDGE
        freopen("inputf.in", "r", stdin);
    	//    freopen("outputf.in", "w", stdout);
    	#endif 
    	cin >> n >> m >> k;
    	cin >> x1 >> s;
    	for(int i = 0; i < m; i++)
    		cin >> a[i].ss;

    	for(int i = 0; i < m; i++)
    		cin >> a[i].ff;

    	for(int i = 0; i < k; i++)
    		cin >> b[i].ss;

    	for(int i = 0; i < k; i++)
    		cin >> b[i].ff;
    	sort(a, a + m);
    	sort(b, b + k);
    	map<int, int> mp1, mp2;
    	for(int i = 0; i < m; i++){
    		mp1[-a[i].ff] = i;
    	}
    	for(int i = 0; i < k; i++){
    		mp2[-b[i].ff] = i;
    	}
    	int dpa[m + 1];
    	int dpb[k + 1];
    	dpa[0] = a[0].ss;
    	dpb[0] = b[0].ss;
    	for(int i = 1; i < m; i++){
    		dpa[i] = max(a[i].ss, dpa[i - 1]);
    	}
    	for(int i = 1; i < k; i++){
    		dpb[i] = max(b[i].ss, dpb[i - 1]);
    	}
    	int ms = n*x1;
    	for(int i = 0; i < m; i++){
    		int r = a[i].ff;
    		int y = a[i].ss;
    		if(s < r)
    			continue;
    		r = r - s;
    		auto it = mp2.lower_bound(r);
    		if(it == mp2.end()){
    			ms = min(ms, n * y);
    		}
    		else{
    			int id = (*it).ss;
    			ms = min(ms, y * (n - dpb[id]));
    		}
    	}

    	for(int i = 0; i < k; i++){
    		int r = b[i].ff;
    		int y = b[i].ss;
    		if(s < r)
    			continue;
    		r = r - s;
    		auto it = mp1.lower_bound(r);
    		if(it == mp1.end()){
    			ms = min(ms, (n - y) * x1);
    		}
    		else{
    			int id = (*it).ss;
    			ms = min(ms, dpa[id] * (n - y));
    		}
    	}
    	cout << ms;
    	return 0;
}