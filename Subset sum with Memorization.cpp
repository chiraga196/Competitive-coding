#include<bits/stdc++.h>
using namespace std;
#define int long long
int dp[1005][1005];
vector<int> v(1005);
int n, t;
int rec(int i, int t){
	if(t == 0)
		return 1;
	if(t < 0)
		return 0;
	if(i < 0 && t == 0)
		return 1;
	if(i < 0)
		return 0;
	int &ans = dp[i][t];
	if(ans != -1)
		return ans;
	ans = 0;
	ans = rec(i - 1, t - v[i]) + rec(i - 1, t);
	return ans;
}
int32_t main(){
	freopen("inputf.in", "r", stdin);
	cin >> n >> t;
	memset(dp, -1, sizeof(dp));
	for(int i = 0; i < n; i++)
		cin >> v[i];
	cout << rec(n - 1, t) <<"\n";

}