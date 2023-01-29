
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
bool is_ok(ll lim,ll n,ll m){
    if(n>=lim&&m>=2*lim)return true;

    if(m<2*lim)return false;
    ll del=m-2*lim;
    n+=del/2;
    if(n>=lim)return true;
    return false;
}
int main() {
    ll n,m;
    cin>>n>>m;
    ll ng=infl;
    ll ok=0;
    while(abs(ok-ng)>1){
        ll mid=(ok+ng)/2;
        if(is_ok(mid,n,m))ok=mid;
        else ng=mid;
    }

    cout<<ok<<endl;
}