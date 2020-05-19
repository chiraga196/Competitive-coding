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
const   int N = 6e5+10, Mod = 1e9 + 7;
int dp[N];
vector<pair<int, int> > v(N);
int n;

int res(int i){

	if(i == n)
		return 0;

	int &ans = dp[i];
	if(ans != -1)
		return ans;
	ans = 1;
	auto y = make_pair(v[i].ss + 1, 0LL);
	int x = lower_bound(v.begin() + i, v.begin() + n, y) - v.begin();
	if(x < n){
		ans = max(ans, 1 + res(x));
	}
	ans = max(ans, res(i + 1));
	return ans;
}

int32_t main(){
    	SKILLER;
    	// #ifndef ONLINE_JUDGE
     //    freopen("inputf.in", "r", stdin);
    	// //    freopen("outputf.in", "w", stdout);
    	// #endif 

        cin >> n;
        memset(dp, -1, sizeof(dp));
        for(int i = 0; i < n; i++){
        	cin >> v[i].ff;
        	cin >> v[i].ss;
        }
        sort(v.begin(), v.begin() + n);
        cout << res(0);

    	return 0;
}