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
const int dx[] = { 1,0 };
const int dy[] = { 0,1 };
template<class T>inline void chmax(T&x,T y){if(x<y)x=y;}
template<class T>inline void chmin(T&x,T y){if(x>y)x=y;}
template<const ll mod>class modint {
private:
    using mint = modint<mod>;
    ll value = 0;
public:
    modint(ll v = 0) {
        v %= mod;
        if(v < 0)v += mod;
        value = v;
    }
    ll val() {
        return value % mod;
    }
    mint operator+(mint fp) {
        return mint(value + fp.val());
    }
    mint operator-(mint fp) {
        return mint(value - fp.val());
    }
    mint operator*(mint fp) {
        return mint(value * fp.val());
    }
    void operator=(mint fp) {
        value = fp.val();
    }
    void operator=(ll val) {
        value = val % mod;
        if(value < 0) {
            value += mod;
        }
    }
    void operator+=(mint fp) {
        (value += fp.val()) %= mod;
        if(value < 0) {
            value += mod;
        }
    }
    void operator-=(mint fp) {
        value = value - fp.val();
        value %= mod;
        if(value < 0) {
            value += mod;
        }
    }
    void operator*=(mint fp) {
        value = value * fp.val();
        value = value % mod;
        if(value < 0) {
            value += mod;
        }
    }
    bool operator==(mint fp) {
        return value == fp.val();
    }
    bool operator<(mint fp) {
        return value < fp.val();
    }
    bool operator>(mint fp) {
        return value > fp.val();
    }
    bool operator<=(mint fp) {
        return value <= fp.val();
    }
    bool operator>=(mint fp) {
        return value >= fp.val();
    }

    ll inv() {
        return mod_pow(mod - 2);
    }
    ll mod_pow(ll exp) {
        ll base = value;
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
    mint operator/(mint a) {
        return mint(a.inv()*value);
    }
    void operator/=(mint a) {
        value = value * a.inv();
        value %= mod;
    }
    friend istream& operator>>(istream& is, mint& mt) {
        ll v;
        is >> v;
        mt = mint(v);
        return is;
    }
    friend ostream& operator << (ostream& os, mint& mt) {
        return os << mt.val();
    }
};
int main() {
    int h,w;
    cin>>w>>h;
    constexpr int mod=100000;
    using mint=modint<mod>;
    mint dp[200][200][2][2];
    rep(i,2)rep(j,2){
        int vi=dx[i]+dx[j];
        int vj=dy[i]+dy[j];
        dp[vi][vj][i][j]+=1;
    }
    //dp[0][0][0][1]=1;
    rep(i,h)rep(j,w)rep(d1,2)rep(d2,2){
        rep(d3,2){
            int ni=i+dx[d3];
            int nj=j+dy[d3];
            if(d1!=d2&&d2!=d3)continue;
            dp[ni][nj][d2][d3]+=dp[i][j][d1][d2];
        }
    }
    mint ans=0;
    rep(i,2)rep(j,2){
        ans+=dp[h-1][w-1][i][j];
    }
    cout<<ans<<endl;
}