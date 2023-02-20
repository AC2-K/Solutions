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
	int n,x,y;
	cin>>n>>x>>y;
	vector<int> a(n),b(n);
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
	}
	vector dp(n+1,vector<vector<int>>(x+1,vector<int>(y+1,inf)));
	dp[0][0][0]=0;
	rep(i,n)rep(xx,x+1)rep(yy,y+1){
		int nx=xx+a[i],ny=yy+b[i];
		chmin(nx,x),chmin(ny,y);
		chmin(dp[i+1][xx][yy],dp[i][xx][yy]);
		chmin(dp[i+1][nx][ny],dp[i][xx][yy]+1);
	}

	int ans=dp[n][x][y]>=inf?-1:dp[n][x][y];

	cout<<ans<<'\n';
}