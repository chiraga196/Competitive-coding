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
        int n; cin >> n;
        vector<int> v(n);
        for(int i = 0; i < n; i++){
        	cin >> v[i];
        }
       // stack<int> st;
        int l[n + 1], r[n + 1];
        fill(l, l + n + 1, -1);
        fill(r, r + n + 1, n);
        stack<int> st;
        for(int i = 0; i < n; i++){
        	while(!st.empty() && v[st.top()] >= v[i])
        		st.pop();
        	if(!st.empty())
        		l[i] =  st.top();
        	//cout << l[i] <<" ";
        	st.push(i);
        }
        stack<int> st1;
        for(int i = n-1; i >= 0; i--){
        	while(!st1.empty() && v[st1.top()] >= v[i])
        		st1.pop();
        	if(!st1.empty())
        		r[i] =  st1.top();
        	st1.push(i);
        }
        int ans[n +2];
        fill(ans, ans + n + 2, 0);
        for(int i = 0; i < n; i++){
        	int ln = r[i] - l[i] - 1;
        	//cout << ln<<" ";
        	ans[ln] = max(ans[ln], v[i]);
        }
        for(int i = n - 1; i >= 1; i--)
        	ans[i] = max(ans[i], ans[i+1]);
        for(int i = 1; i <= n; i++)
        	cout << ans[i] <<" ";
    	return 0;
}