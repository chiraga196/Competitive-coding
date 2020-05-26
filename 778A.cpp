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
string s, t;
vector<int> v;
bool check(int r){
	vector<bool> ntu(s.length(), 1);
	for(int i = 0; i <= r; i++){
		ntu[v[i] - 1] = 0;
	}
	int j = 0, i = 0;
	while(i < s.length() && j < t.length()){
		if(s[i] == t[j] && ntu[i] == 1){
			i++;
			j++;
		}
		else i++;
	}
	if(j == t.length())
		return true;
	else return false;
}
int binary_search(int low, int end){
	while(low < end){
		int mid = low + end + 1;
		mid /= 2;
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
        cin >> s;
        cin >> t;
        int n = s.length();
       	v.resize(n);
       	for(auto &x:v)
       		cin >> x;
       	int ans = binary_search(-1, n - 1);
       	cout << ans + 1;
    	return 0;
}