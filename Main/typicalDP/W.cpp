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
template<
    class X, class M,
    X(*fx)(X, X), const X&ex,
    M(*fm)(M, M), const M&em,
    X(*fxm)(X, M)
>
class lazy_segtree {
    int sz;
    vector<X> dat;
    vector<M> lz;
    void Init(int n) {
        dat.assign(4 * n, ex);
        lz.assign(4 * n, em);
        int x = 1;
        while (n > x) {
            x <<= 1;
        }
        sz = x;
    }
public:
    lazy_segtree(int n) {
        lazy_segtree(n, vector<X>(n, ex));
    }
    lazy_segtree(int n, const vector<X>& a) {
        Init(n);
        for (int i = 0; i < n; i++) {
            set(i, a[i]);
        }
        build();
    }
public:
    void set(int pos, X x) {
        assert(0 <= pos && pos < sz);
        dat[pos + sz - 1] = x;
    }
    void build() {
        for (int i = sz - 2; i >= 0; i--) {
            dat[i] = fx(dat[2 * i + 1], dat[2 * i + 2]);
        }
    }

private:
    void eval(int pos) {
        if (lz[pos] == em) return;
        if (pos < sz - 1) {
            lz[2 * pos + 1] = fm(lz[2 * pos + 1], lz[pos]);
            lz[2 * pos + 2] = fm(lz[2 * pos + 2], lz[pos]);
        }
        dat[pos] = fxm(dat[pos], lz[pos]);
        lz[pos] = em;
    }

private:
    void update(int L, int R, int l, int r, M x, int k) {
        eval(k);
        if (L <= l && r <= R) {
            lz[k] = fm(lz[k], x);
            eval(k);
        }
        else if (L < r && l < R) {
            int mid = (l + r) >> 1;
            update(L, R, l, mid, x, 2 * k + 1);
            update(L, R, mid, r, x, 2 * k + 2);
            dat[k] = fx(dat[2 * k + 1], dat[2 * k + 2]);
        }
    }
public:
    void update(int l, int r, M x) {
        assert(0 <= l && l <= r && r <= sz);
        update(l, r, 0, sz, x, 0);
    }

private:
    X prod(int L, int R, int l, int r, int k) {
        eval(k);
        if (r <= L || R <= l) {
            return ex;
        }
        else if (L <= l && r <= R) {
            return dat[k];
        }
        else {
            int mid = (l + r) >> 1;
            X vl = prod(L, R, l, mid, 2 * k + 1);
            X vr = prod(L, R, mid, r, 2 * k + 2);
            return fx(vl, vr);
        }
    }

public:
    X prod(int l, int r) {
        assert(0 <= l && l <= r && r <= sz);
        return prod(l, r, 0, sz, 0);
    }

    X operator[](int pos) {
        return dat[pos + sz - 1];
    }
};
//@brief 遅延評価セグメント木
//X:datのほうのモノイド,M:作用素の集合
//fx:X × X -> X 
//fm:M × M -> M
//fxm:X × M -> X

constexpr ll ex =-infl;
constexpr ll em = 0;
ll fx(ll x, ll y) { return max(x,y); }
ll fm(ll x, ll y) { return x+y; }
ll fmx(ll x, ll y) { return x+y; }

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,ll>>> lefts(n+1);
    rep(i,m){
        int l,r;
        ll a;
        cin>>l>>r>>a;
        l--;
        lefts[r].emplace_back(l,a);
    }

    lazy_segtree<ll,ll,fx,ex,fm,em,fmx> dp(n+1,vector<ll>(n,0));
    for(int i=1;i<=n;i++){
        //追加するとき
        ll v=0;
        for(auto l:lefts[i]){
            v+=l.second;
        }

        ll mx=dp.prod(0,i);
        dp.update(i,i+1,mx+v-dp[i]);
        for(auto p:lefts[i]){
            int left=p.first;
            ll v2=p.second;
            dp.update(left+1,i,v2);
        }
    }


    cout<<dp.prod(0,n+1)<<endl;
}