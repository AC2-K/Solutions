#include<bits/stdc++.h>
using namespace std;
//cout << fixed << setprecision(10);
#define rep(i, N)  for(int i=0;i<(N);i++)
#define all(x) (x).begin(),(x).end()
#define popcount(x) __builtin_popcount(x)
using ll = long long;
using ld = long double;
using graph = vector<vector<int>>;
using P = pair<int, int>;
const int inf = 1e9;
const ll infl = 1e18;
const ld eps = ld(0.000000001);
const long double pi = acos(-1);
const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };
template<class T>void chmax(T&x,T y){if(x<y)x=y;}
template<class T>void chmin(T&x,T y){if(x>y)x=y;}
ll sum(ll n){
    //sum i (i=1 to n)
    return n*(n+1)/2;
}
ll mod_pow(ll base, ll exp, ll mod) {
    if(base==0)return 0;
    ll ans = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) {
            ans *= base;
            ans %= mod;
        }
        base *= base;
        base %= mod;
        exp >>= 1;
    }
    return ans;
}
using i128=__int128_t;
int main() {
    ll n,m;
    cin>>n>>m;
    i128 ans=0,perm=1;
    rep(i,n){
        ans+=perm%m*sum(i)%m*mod_pow(n,n-1-i,m)%m;
        ans%=m;
        (perm*=(n-i-1)%m)%=m;
    }
    (ans*=n)%=m;
    ll ans_out=ans;
    cout<<ans_out<<endl;
}