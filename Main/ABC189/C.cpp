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
class SegmentTree {
    using fx = function<X(X, X)>;
    int n;
    const fx op;
    const X ex;
    vector<X> dat;
public:
    SegmentTree(int n_, fx op, X ex) : n(), op(op), ex(ex), dat(n_ * 4, ex) {
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
    inline X query(int a, int b) {
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

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto&aa:a)cin>>aa;
    vector<vector<int>> rmq(n,vector<int>(n));
    rep(r,n)rep(l,r+1){
        if(l==r){
            rmq[l][r]=a[l];
        }else if(l>r){
            rmq[l][r]=inf;
        }else{
            rmq[l][r]=min(a[r],rmq[l][r-1]);
        }
    }
    ll ans=0;
    rep(r,n)rep(l,r+1){
        chmax(ans,1ll*(r-l+1)*rmq[l][r]);
    }
    cout<<ans<<endl;
}