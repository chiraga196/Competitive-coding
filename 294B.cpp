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
int dp[105][205][1000];
vector<pair<int, int>> v;
int n;
int res(int i, int thick, int hor){
	if((i == n && hor > thick) || hor > 1000){
		return 1e9;
	}
	else if(i == n){
		return thick;
	}
	
	int &ans = dp[i][thick][hor];
	if(ans != -1)
		return ans;
	ans = min(res(i + 1, thick + v[i].ss, hor), res(i + 1, thick, hor + v[i].ff));
	return ans;

}
int32_t main(){
    	SKILLER;
    	#ifndef ONLINE_JUDGE
        freopen("inputf.in", "r", stdin);
    	//    freopen("outputf.in", "w", stdout);
    	#endif 
    	memset(dp, -1, sizeof(dp));
        cin >> n;
        v.resize(n);
        for(int i = 0; i < n; i++){
        	cin >> v[i].ss;
        	cin >> v[i].ff;
        }
        cout << res(0, 0, 0);
    	return 0;
}