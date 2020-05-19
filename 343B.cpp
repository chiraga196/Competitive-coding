#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ff first
#define ss second

int32_t main() {
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);cout.tie(NULL);
		// #ifndef ONLINE_JUDGE
	 	//    freopen("inputf.in", "r", stdin);
	 	//    //    freopen("outputf.in", "w", stdout);
	 	//    #endif

	    string s; cin >> s;
	    string nw = "";
	    if(s.length()&1){
	    	cout<<"No";
	    	exit(0);
	    }
	    for(auto x:s){
	    	if(nw.size() == 0){
	    		nw += x;
	    		continue;
	    	}
	    	else{
	    		if(nw.back() == x)
	    			nw.pop_back();
	    		else nw += x;
	    	}
	    }
	    if(nw.length())
	    	cout <<"No\n";
	  	else cout << "Yes\n";
}