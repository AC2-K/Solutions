#include<bits/stdc++.h>
using namespace std;
#define rep(i, N)  for(int i=0;i<(N);i++)
#define all(x) (x).begin(),(x).end()
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
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
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin>>n;
    ll m=n;
    while((m&1)==0){
        m>>=1;
    }
    ll ans=0;
    for(ll d=1;d*d<=m;d++){
        if(m%d!=0)continue;
        if(d*d==m)ans+=1;
        else ans+=2;
    }
    ans<<=1;
    cout<<ans<<'\n';
}