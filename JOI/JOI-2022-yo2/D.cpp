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
    int n,k;
    cin>>n>>k;
    vector<ll> a(n);
    for(auto&aa:a){
        cin>>aa;
    }
    vector<vector<ll>> dp(n,vector<ll>(n,-infl));
    ll res=0;
    rep(i,n)rep(j,i){
        if(j>0){
            dp[i][j] = dp[i][j-1];
        }
        dp[i][j] = max(dp[i][j],a[i]+a[j]);
        if(0<=i-k&&j>0){
            dp[i][j] = max(dp[i][j],dp[j][min(j-1,i-k)]+a[i]);
        }
        chmax(res,dp[i][j]);
    }
    cout<<res<<'\n';
    /*
   ll res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (j > 0) {
                dp[i][j] = dp[i][j - 1];
            }
            dp[i][j] = max(dp[i][j], a[i] + a[j]);
            if (0 <= i - k && j > 0) {
                dp[i][j] = max(dp[i][j], dp[j][min(j - 1, i - k)] + a[i]);
            }
            res = max(res, dp[i][j]);
        }
    }
    cout << res << endl;
    */
}