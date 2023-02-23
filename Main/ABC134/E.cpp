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

template<class S, S(*op)(S, S), S(*e)()>
class segtree {
    int n;
    vector<S> dat;
    void Init(int n_) {
        int x = 1;
        while (n_ > x) {
            x <<= 1;
        }
        n = x;
    }
public:
    segtree(int n_) : segtree(vector<S>(n_, e())) {   }
    segtree(const vector<S>& v) :dat(4 * v.size()) {
        Init(v.size());
        for (int i = 0; i < v.size(); i++) {
            set(i, v[i]);
        }
        build();
    }
    inline void set(int pos, S val) {
        assert(0 <= pos && pos < n);
        dat[pos + n - 1] = val;
    }
    void build() {
        for (int k = n - 2; k >= 0; k--) {
            dat[k] = op(dat[(k << 1) + 1], dat[(k << 1) + 2]);
        }
    }

    void update(int pos, S val) {
        assert(0 <= pos && pos < n);
        pos += n - 1;
        dat[pos] = val;
        while (pos > 0) {
            pos = (pos - 1) >> 1;
            dat[pos] = op(dat[(pos << 1) + 1], dat[(pos << 1) + 2]);
        }
    }
    inline S prod(int a, int b) {
        assert(0 <= a && b <= n);
        assert(a <= b);
        if (a == 0 && b == n)return dat[0];
        return prod(a, b, 0, 0, n);
    }

private:
    S prod(int a, int b, int id, int l, int r) {
        if (r <= a || b <= l) {
            return e();
        }
        else if (a <= l && r <= b) {
            return dat[id];
        }
        else {
            int mid = (l + r) >> 1;
            S vl = prod(a, b, (id << 1) + 1, l, mid);
            S vr = prod(a, b, (id << 1) + 2, mid, r);
            return op(vl, vr);
        }
    }

public:
    //a[pos] <- a[pos]・x
    void add(int pos, S x) {
        update(pos, op(dat[n + pos - 1], x));
    }

    S operator [](int pos) {
        return dat[n + pos - 1];
    }
};
namespace for_segtree{
    int op(int x, int y) { return max(x,y); }
    int e() { return 0; }
};
int LIS(vector<int> &a) {
    int n=a.size();
    vector<int> a_val=a;
    sort(all(a_val));
    a_val.erase(unique(all(a_val)),a_val.end());
    for(auto&aa:a){
        aa=lower_bound(all(a_val),aa)-a_val.begin();
    }

    segtree<int,for_segtree::op,for_segtree::e> seg(n);

    for(auto&aa:a){
        int mx=seg.prod(aa,n);
        seg.add(aa,mx+1);
    }

    return seg.prod(0,n);
}
int main() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto&aa:a){
        cin>>aa;
    }

    cout<<LIS(a)<<'\n';
}