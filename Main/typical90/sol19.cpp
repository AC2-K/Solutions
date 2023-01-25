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
template<class T>void chmax(T&x,T y){if(x<y)x=y;}
template<class T>void chmin(T&x,T y){if(x>y)x=y;}
int main() {
    int n;
    cin>>n;
    vector<int> a(2*n);
    for(auto&aa:a)cin>>aa;
    vector<vector<ll>> dp(2*n+1,vector<ll>(2*n+1,infl));    //dp[l][r]:=[l,r]を取り除くために必要なコスト
    auto rec=[&](auto f,int l,int r)-> ll {
        if(dp[l][r]<infl)return dp[l][r];
        if(l>r)return 0;

        ll res=infl;
        chmin(res,f(f,l+1,r-1)+abs(a[l]-a[r]));
        for(int i=l+1;i+1<r;i+=2){
            ll cost=f(f,l,i)+f(f,i+1,r);
            chmin(res,cost);
        }

        return dp[l][r]=res;
    };

    cout<<rec(rec,0,2*n-1)<<'\n';
}