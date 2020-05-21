#include<bits/stdc++.h>
using namespace std;
multiset<int> st;
vector<int> vt;
vector<pair<int, int>> adj[600005];
int n, m, k;
vector<int> cost;
vector<int> vis;
#define ff first
#define ss second
#define int long long
// void dfs(int i, int par, int cst = 0){
//     vis[i] = 1;
//     for(auto x:adj[i]){
//         if(x.ff != par){
//             if(!vis[x.ff]){
//                 if(st.size() < k){
//                     st.insert(x.ss);
//                     cost[x.ff] = cst;
//                     dfs(x.ff, i, cst);
//                     st.erase(st.find(x.ss));
//                 }
//                 else{
//                     int a = *st.begin();
//                     st.erase(st.find(a));
//                     cost[x.ff] = min(x.ss, a) + cst;
//                     st.insert(max(x.ss, a));
//                     dfs(x.ff, i, cost[x.ff]);
//                     st.erase(st.find(max(x.ss, a)));
//                     st.insert(a);
//                 }
//             }
//             else{
//                 if(st.size() < k){
//                     if(cost[x.ff] > cst){
//                         cost[x.ff] = cst;
//                         st.insert(x.ss);
//                         dfs(x.ff, i, cost[x.ff]);
//                         st.erase(st.find(x.ss));
//                     }
//                 }
//                 else{
//                     int a = *st.begin();
//                     if(cost[x.ff] > min(x.ss, a) + cst){
//                         cost[x.ff] = min(x.ss, a) + cst;
//                         st.erase(st.find(a));
//                         st.insert(max(x.ss, a));
//                         dfs(x.ff, i, cost[x.ff]);
//                         st.erase(st.find(max(x.ss, a)));
//                         st.insert(a);
//                     }
//                 }
//             }
//         }
//     }
// }
int32_t main(){
 
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);cout.tie(NULL);
		#ifndef ONLINE_JUDGE
	        freopen("inputf.in", "r", stdin);
	    	//    freopen("outputf.in", "w", stdout);
	    	#endif 
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++)
        adj[i].clear();
    for(int i = 0; i < m; i++){
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
   // vis.resize(n + 1, 0);
    //cout<<INT_MAX;
    cost.resize(n + 1, 1e9);
    priority_queue <pair<pair<int, int>, pair<multiset<int>, int> >, vector<pair<pair<int, int> , pair<multiset<int>, int>>> , greater<pair<pair<int, int> , pair<multiset<int>, int>>> > pq;
    multiset<int> st;
    vector<int> par(n+1, 0);
    pq.push({{0, 0}, {st, 1}});
    cost[1] = 0;
    par[1] = 1; 
    while(!pq.empty()){
        auto x = pq.top();
        pq.pop();
        for(auto a:adj[x.ss.ss]){
        	if(par[x.ss.ss] == a.ff)
        		continue;
            int k1 = x.ff.ff;
            int cst = x.ff.ss;
            multiset<int> st = x.ss.ff;
            if(k1 < k){
                st.insert(a.ss);
            }
            else{
                int y = *st.begin();
                st.erase(st.begin());
                st.insert(max(1LL*y, 1LL*a.ss));
                cst += min(1LL*a.ss, y);
            }
            if(cost[a.ff] >= cst){
                cost[a.ff] = cst;
                par[a.ff] = x.ss.ss;
                pair<pair<int, int>, pair<multiset<int>, int> > r = {{min(1LL*k1 + 1, k*1LL), cst}, {st, a.ff}};
                pq.push(r);
            }
        }
       // cout << "\n";
    }
    for(int i = 1; i <= n; i++)
    	cout << cost[i] << " ";
    std::multiset<int> v1 , v2;   
}