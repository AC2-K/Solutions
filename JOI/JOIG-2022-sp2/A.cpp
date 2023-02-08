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
int main() {
    int n,l;
    cin>>n>>l;
    SegmentTree<ll> a(n,[](ll s,ll t){return s+t;},0);
    rep(i,n){
        int ai;
        cin>>ai;
        a.set(i,ai);
    }
    a.build();
    vector<int> pack(n+1),weight(n+1);
    vector<bool> flag(n+1,false);
    //memo1[x]:=[x,n)を詰めるのに必要な箱の個数
    //memo2[x]:=[x,n)を詰めるとき、最後に詰める箱に入れるメロンの重さの合計
    pack[n]=0,weight[n]=0;
    function<pair<int,int>(int)> f=[&](int x)-> P {
        if(x>=n)return P(0,0);
        if(flag[x]){
            return P(pack[x],weight[x]);
        }
        flag[x]=true;
        if(a.query(x,n)<=l){
            weight[x]=a.query(x,n);
            pack[x]=1;
            return P(pack[x],weight[x]);
        }
        //どこまで詰められるか?
        int ng=n;
        int ok=x;
        while(abs(ok-ng)>1){
            int md=(ok+ng)>>1;
            if(a.query(x,md)<=l)ok=md;
            else ng=md;
        }
        auto res=f(ok);
        pack[x]=res.first+1;
        weight[x]=res.second;

        return P(pack[x],weight[x]);
    };

    rep(x,n){
        f(x);
        cout<<pack[x]<<' '<<weight[x]<<'\n';
    }
}