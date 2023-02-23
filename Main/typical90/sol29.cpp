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
    class S, class F,
    S(*op)(S, S), S(*e)(),
    F(*comp)(F, F), F(*id)(),
    S(*mapping)(S, F)
>
class lazy_segtree {
    int sz;
    vector<S> dat;
    vector<F> lz;
public:
    lazy_segtree(int n) :lazy_segtree(vector<S>(n, e())) {    }
    lazy_segtree(const vector<S>& a) :dat(4 * a.size(), e()), lz(4 * a.size(), id()) {
        int x = 1;
        while (a.size() > x) {
            x <<= 1;
        }
        sz = x;
        for (int i = 0; i < a.size(); i++) {
            set(i, a[i]);
        }
        build();
    }
public:
    void set(int pos, S x) {
        assert(0 <= pos && pos < sz);
        dat[pos + sz - 1] = x;
    }
    void build() {
        for (int i = sz - 2; i >= 0; i--) {
            dat[i] = op(dat[2 * i + 1], dat[2 * i + 2]);
        }
    }

private:
    void eval(int pos) {
        if (lz[pos] == id()) return;
        if (pos < sz - 1) {
            lz[2 * pos + 1] = comp(lz[2 * pos + 1], lz[pos]);
            lz[2 * pos + 2] = comp(lz[2 * pos + 2], lz[pos]);
        }
        dat[pos] = mapping(dat[pos], lz[pos]);
        lz[pos] = id();
    }

private:
    void update(int L, int R, int l, int r, F x, int k) {
        eval(k);
        if (L <= l && r <= R) {
            lz[k] = comp(lz[k], x);
            eval(k);
        }
        else if (L < r && l < R) {
            int mid = (l + r) >> 1;
            update(L, R, l, mid, x, 2 * k + 1);
            update(L, R, mid, r, x, 2 * k + 2);
            dat[k] = op(dat[2 * k + 1], dat[2 * k + 2]);
        }
    }
public:
    void update(int l, int r, F x) {
        assert(0 <= l && l <= r && r <= sz);
        update(l, r, 0, sz, x, 0);
    }

private:
    S prod(int L, int R, int l, int r, int k) {
        eval(k);
        if (r <= L || R <= l) {
            return e();
        }
        else if (L <= l && r <= R) {
            return dat[k];
        }
        else {
            int mid = (l + r) >> 1;
            S vl = prod(L, R, l, mid, 2 * k + 1);
            S vr = prod(L, R, mid, r, 2 * k + 2);
            return op(vl, vr);
        }
    }

public:
    S prod(int l, int r) {
        assert(0 <= l && l <= r && r <= sz);
        return prod(l, r, 0, sz, 0);
    }

    S operator[](int pos) {
        return prod(pos, pos + 1);
    }
};
//@brief 遅延評価セグメント木
//S:datのほうのモノイド,F:作用素の集合
//op:S × S -> S 
//composition:F × F -> F
//mapping:S × F -> S
using S = int;
using F = int;
S e() { return 0;}
F id() { return 0;}
S op(S x, S y) { return max(x,y);}
F comp(F x, F y) { return y;}
S mapping(S x, F y) { return y;}
int main() {
    int w,n;
    cin>>w>>n;
    lazy_segtree<S,F,op,e,comp,id,mapping> seg(w);
    rep(i,n){
        int l,r;
        cin>>l>>r;
        l--,r--;
        int h=seg.prod(l,r+1);
        cout<<h+1<<'\n';
        seg.update(l,r+1,h+1);
    }
    /*
    rep(i,w){
        cout<<seg[i]<<' ';
    }
    cout<<'\n';
    */
}