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
template<class X>
class segtree {
    using fx = function<X(X, X)>;
    int n;
    const fx op;
    const X ex;
    vector<X> dat;
public:
    segtree(int n_, fx op, X ex) : n(), op(op), ex(ex), dat(n_ * 4, ex) {
        int x = 1;
        while (n_ > x) {
            x <<= 1;
        }
        n = x;
    }
    inline void set(int pos, X val) {
        assert(0 <= pos && pos < n);
        dat[pos + n - 1] = val;
    }
    void build() {
        for (int k = n - 2; k >= 0; k--) {
            dat[k] = op(dat[(k << 1) + 1], dat[(k << 1) + 2]);
        }
    }

    void update(int pos, X val) {
        assert(0 <= pos && pos < n);
        pos += n - 1;
        dat[pos] = val;
        while (pos > 0) {
            pos = (pos - 1) >> 1;
            dat[pos] = op(dat[(pos << 1) + 1], dat[(pos << 1) + 2]);
        }
    }
    inline X prod(int a, int b) {
        assert(0 <= a && b <= n);
        assert(a <= b);
        if (a == 0 && b == n)return dat[0];
        return query(a, b, 0, 0, n);
    }

private:
    X query(int a, int b, int id, int l, int r) {
        if (r <= a || b <= l) {
            return ex;
        }
        else if (a <= l && r <= b) {
            return dat[id];
        }
        else {
            int mid = (l + r) >> 1;
            X vl = query(a, b, (id << 1) + 1, l, mid);
            X vr = query(a, b, (id << 1) + 2, mid, r);
            return op(vl, vr);
        }
    }



public:
    inline X get(int pos) { 
        return dat[pos + n - 1]; 
    }
    //a[pos] <- a[pos]・x
    void action(int pos, int x) {
        update(pos, op(get(pos), x));
    }
};
template<
    class X, class M,
    X(*fx)(X, X), const X& ex,
    M(*fm)(M, M), const M& em,
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
using X=int;
using M=int;
constexpr X ex = inf;
constexpr X em = inf;
X fx(X x, X y) { return min(x,y); }
M fm(M x,M y) { return min(x,y); }
M fmx(X x, M y) { return min(x,y); }
int main() {
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    for(auto&aa:a){
        cin>>aa;
    }
    vector<int> idx(n);
    lazy_segtree<X,M,fx,ex,fm,em,fmx> ls(n,vector<int>(n,inf));
    rep(i,m){
        int l,r;
        cin>>l>>r;
        l--,r--;
        ls.update(l,r+1,l);
    }
    rep(i,n){
        ls.update(i,i+1,i);
    }
    #ifdef ONLINE_JUDGE
    #else
    rep(i,n){
        cout<<ls[i]<<' ';
    }
    cout<<endl;
    #endif
    segtree<ll> dp(n,[](ll v,ll u){return max(v,u);},0);
    rep(i,n){
        int l=ls[i];
        ll mx=dp.prod(0,l);
        dp.update(i,mx+a[i]);
    }
    cout<<dp.prod(0,n)<<endl;
}