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
std::vector<int> v;
int k;
int x;
void rec(int l, int r){
	if(k == 0){
		;
		for(int i = l; i < r; i++){
			v[i] = x;
			//cout << i <<" "<<x <<"\n";
			x--;
		}
		sort(v.begin() + l, v.begin() + r );
	}
	else if(r - 1 == l){
		v[l] = x;
		x--;
	}
	else{
		if(k == 1){
			cout<<"-1";
			exit(0);
		}
		k -= 2;
		int mid = l + r;
		mid /= 2;
		rec(l, mid);
		rec(mid, r);
	}
}
int32_t main(){
    	SKILLER;
    	// #ifndef ONLINE_JUDGE
     //    freopen("inputf.in", "r", stdin);
    	// //    freopen("outputf.in", "w", stdout);
    	// #endif 
        int n; cin >> n >> k;
        if(k == 1){
        	for(int i = 1; i <= n; i++)
        		cout << i <<" ";
        	return 0;
        }
        k--;
        x = n;
        v.resize(n);
        rec(0, n);
        if(k > 0){
        	cout<<"-1";
        	exit(0);
        }
        for(int i = 0; i < n; i++)
        	cout << v[i] <<" ";
    	return 0;
}