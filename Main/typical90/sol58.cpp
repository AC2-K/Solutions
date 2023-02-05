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
    const int M=1e5;
    int n;
    ll k;
    cin>>n>>k;
    const int BIT=60;
    vector<vector<int>> dp(BIT+1,vector<int>(M+1));
    auto dgt_sum=[&](int n)-> int {
        auto s=to_string(n);
        int sum=0;
        for(auto&c:s){
            sum+=(c-'0');
        }
        return sum;
    };
    rep(x,M+1){
        int y=dgt_sum(x);
        dp[0][x]=(x+y)%M;
    }
    rep(i,BIT){
        rep(j,M+1){
            dp[i+1][j]=dp[i][dp[i][j]];
        }
    }
    rep(i,BIT+1){
        if(k&(1ll<<i)){
            n=dp[i][n];
        }
    }
    cout<<n<<endl;
}