#include<bits/stdc++.h>
using namespace std;
#define rep(i, N)  for(int i=0;i<(N);i++)
#define all(x) (x).begin(),(x).end()
#define popcount(x) __builtin_popcount(x)
using ll = long long;
//using i128=__int128_t;
using ld = long double;
using graph = vector<vector<int>>;
using P = pair<int, int>;
const int inf = 1e9;
const ll infl = 1e18;
const ld eps = 1e-6;
const long double pi = acos(-1);
const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };
template<class T>inline void chmax(T&x,T y){if(x<y)x=y;}
template<class T>inline void chmin(T&x,T y){if(x>y)x=y;}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	vector<int> a(n);
	for(auto&aa:a){
		cin>>aa;
	}

	graph g(n);
	rep(i,m){
		int x,y;
		cin>>x>>y;
		x--,y--;
		g[x].push_back(y);
	}
	vector<int> dp(n,-inf);	//dp[v]:=v-> のパスにおいて、v以外の頂点における売値の最大値
	vector<bool> flag(n,false);
	function<int(int)> f=[&](int v)-> int {
		if(flag[v]){
			return dp[v];
		}

		flag[v]=true;
		for(const auto&nx:g[v]){
			chmax(dp[v],max(a[nx],f(nx)));
		}
		return dp[v];
	};
	int mx=-inf;
	for(int v=0;v<n;v++){
		chmax(mx,f(v)-a[v]);
	}
	cout<<mx<<'\n';
}