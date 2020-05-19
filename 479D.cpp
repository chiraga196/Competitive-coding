//Hey1 u r far away to know this
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
        int l; cin >> l;
        int x, y; cin >> x >> y;
        map<int, int> mp;
        mp.clear();
        for(int i = 0; i < n; i++){
        	int a; cin >> a;
        	mp[a] = 1;
        }
        int flag = 0;
        for(auto a:mp){
        	//cout << a.ff;
        	int y1 = a.ff - x;
        	if(y1 >= 0 && mp.count(y1) >= 1)
        		flag = 1;
        	y1 = x + a.ff;
        	if(y1 <= l && mp.count(y1) >= 1)
        		flag = 1;
        }
        map<int, int> ans;
        int left = -2, right = -2;
        if(!flag){
        	left = -1;
        	for(auto a:mp){
        		if(a.ff - x >= 0){
        			ans[a.ff - x] = 1;
        			left = a.ff - x;
        		}
        		if(a.ff + x <= l){
        			ans[a.ff + x] = 1;
        		}
        	}
        }
        flag = 0;
        for(auto a:mp){
        	int y1 = a.ff - y;
        	if(mp.count(y1) >= 1)
        		flag = 1;
        	y1 = y + a.ff;
        	if(mp.count(y1) >= 1)
        		flag = 1;
        }
        if(!flag){
        	right = -1;
        	set<int> st;
        	for(auto a:mp){
        		if(a.ff - y >= 0){
        			if(st.find(a.ff - y) == st.end()){
        				ans[a.ff - y]++;
        				right = a.ff - y;
        				st.insert(a.ff - y);
        			}
        		}
        		if(a.ff + y <= l){
        		//	cout << a.ff + 
        			if(st.find(a.ff + y) == st.end()){
        				ans[a.ff + y]++;
        				st.insert(a.ff + y);
        			}
        		}
        	}
        }
        
        vector<int> pr;
        for(auto a:ans){
        	if(ans[a.ff] == 2){
        		cout << "1\n";
        		cout << a.ff;
        		return 0;
        	}
        }
        if(left == -1){
        	pr.pb(0);
        	pr.pb(x);
        }
        else if(left != -2) pr.pb(left);
        if(right > -1){
        	pr.pb(right);

        } 
        else if(right == -1){
        	if(mp[0])
        		pr.pb(y);
        	else{
        		pr.pb(0);
        		pr.pb(y);
        	}
        }
        cout << pr.size() <<"\n";
        if(pr.size() == 0)
        	return 0;
        for(auto x1:pr)
        	cout << x1 <<" ";
    	return 0;
}