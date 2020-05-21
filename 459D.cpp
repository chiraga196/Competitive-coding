//Hey u r far away to know this
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
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
template<typename T, class cmp = std::less_equal<T>>
using Tree = tree<T, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;
const   int N = 1e6+5, Mod = 1e9 + 7;

int32_t main(){
    	SKILLER;
    	#ifndef ONLINE_JUDGE
        freopen("inputf.in", "r", stdin);
    	//    freopen("outputf.in", "w", stdout);
    	#endif 
        int n; cin >> n;
        vector<int> v(n), a(n), b(n);
        for(auto &x:v)
        	cin >> x;

        map<int, int> cnt;
        for(int i = n-1; i >= 1; i--){
        	cnt[v[i]]++;
        	b[i] = cnt[v[i]];
        }
        cnt.clear();
        for(int i = 0; i  < n-1; i++){
        	cnt[v[i]]++;
        	a[i] = cnt[v[i]];
        }
        Tree<int> st;
        st.insert(b[n-1]);
        int ans = 0;
        for(int i = n-2; i >= 0; i--){
        
        	ans += st.order_of_key(a[i]);
        	st.insert(b[i]);
        }
        cout << ans ;
    	return 0;
}