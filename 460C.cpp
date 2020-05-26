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
int n, m, w;
int check(int x){
	vector<int> l(n + 2, 0);
	int ms = 0;
	l[0] = 0;

	for(int i = 1; i <= n; i++){
		int y = v[i] + l[i - 1] + l[i];
		l[i] += l[i-1];
		if(y >= x)
			continue;
		else{
			int req = x - y;
			ms += req;
			l[i] += req;
			l[min(i + w, n + 1)] -= req;

		}

	}
	return ms <= m;
}
int binary_search(int low, int end){
	while(low < end){
		int mid = low + end + 1;
		mid >>= 1;
		if(check(mid)){
			low = mid;
		}
		else end = mid - 1;

	}
	return low;
}
int32_t main(){
    	SKILLER;
    	#ifndef ONLINE_JUDGE
        freopen("inputf.in", "r", stdin);
    	//    freopen("outputf.in", "w", stdout);
    	#endif 
        cin >> n >> m >> w;
        v.resize(n + 1);
        for(int i = 1; i <= n; i++){
        	cin >> v[i];
        }
        //cout << check(1000000000);
        int ans = binary_search(-1, 1e11);
        cout << ans <<"\n";
    	return 0;
}