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
const ld eps = 1e-6;
const long double pi = acos(-1);
const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };
template<class T>void chmax(T&x,T y){if(x<y)x=y;}
template<class T>void chmin(T&x,T y){if(x>y)x=y;}
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
int main() {
    int p,n;
    scanf("%d%d",&p,&n);
    vector<ll> cnt(p);    //count_x[v]:=x^n=vなるxの個数
    for(int x=0;x<p;x++){
        cnt[mod_pow(x,n,p)]++;
    }
    vector<ll> cnt2(p);
    for(int xn=0;xn<p;xn++)for(int yn=0;yn<p;yn++){
        cnt2[(xn+yn)%p]+=cnt[xn]*cnt[yn];
    }

    ll ans=0;
    for(int z=0;z<p;z++){
        ans+=cnt2[mod_pow(z,n,p)];
    }
    cout<<ans<<endl;
}