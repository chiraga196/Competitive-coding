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
        int t; cin >> t;
        while(t--){
        	int n, m, a, b; cin >> n >> m >> a >> b;
        	vector<int> row(n, 0), col(m, 0);
        	int flag  = 1;
        	vector<vector<int> > matrix(n, vector<int> (m, 0));
        	for(int i = 0; i < n; i++){
        		int r = a;
        		for(int j = 0; j < m; j++){
        			if(col[j] < b){
        				col[j]++;
        				matrix[i][j] = 1;
        				r--;
        			}
        			if(r == 0)
        				break;
        		}
        		if(r > 0){
        			flag = 0;
        			break;
        		}
        	}
        	if(!flag)
        		cout << "NO\n";
        	else {
        		cout << "YES\n";
        		for(int i = 0; i < n; i++){
        			for(int j = 0; j < m; j++){
        				cout << matrix[i][j] ;
        			}
        			cout << "\n";
        		}
        	}
        }
    	return 0;
}