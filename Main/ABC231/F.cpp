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
template<class T>void chmax(T&x,T y){if(x<y)x=y;}
template<class T>void chmin(T&x,T y){if(x>y)x=y;}
template <class X>
class SegmentTree {
    using fx = function<X(X, X)>;
    int n;
    fx op;
    const X ex;
    vector<X> dat;
public:
    SegmentTree(int n_, fx fx_, X ex_) : n(), op(fx_), ex(ex_), dat(n_ * 4, ex_) {
        int x = 1;
        while (n_ > x) {
            x *= 2;
        }
        n = x;
    }
    void set(int pos, X val) { 
        dat[pos + n - 1] = val;
    }
    void build() {
        for (int k = n - 2; k >= 0; k--){
            dat[k] = op(dat[2 * k + 1], dat[2 * k + 2]);
        }
    }

    void update(int pos, X val) {
        pos += n - 1;
        dat[pos] = val;
        while (pos > 0) {
            pos = (pos - 1) / 2;
            dat[pos] = op(dat[pos * 2 + 1], dat[pos * 2 + 2]);
        }
    }
    void add(int pos,X val){
        update(pos,get(pos)+val);
    }
    X query(int a, int b) { 
        if(a==0&&b==n)return dat[0];
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
            X vl = query(a, b, id * 2 + 1, l, (l + r) / 2);
            X vr = query(a, b, id * 2 + 2, (l + r) / 2, r);
            return op(vl, vr);
        }
    }

public:
    X get(int pos){return dat[pos+n-1];}
};
vector<int> press(vector<int>&A){
    vector<int> B;
    vector<int> T;
    rep(i,A.size())T.push_back(A[i]);
    sort(all(T));
    T.erase(unique(all(T)),T.end());
    rep(i,A.size()){
        int pos=lower_bound(all(T),A[i])-T.begin();
        B.push_back(pos);
    }
    return B;
}
int main() {
    int n;
    cin>>n;
    vector<int> a(n),b(n);
    for(auto&aa:a)cin>>aa;
    for(auto&bb:b)cin>>bb;
    a=press(a),b=press(b);
    vector<P> vec(n);
    rep(i,n){
        vec[i]=make_pair(-a[i],b[i]);
    }
    sort(all(vec));
    //A_i>=A_jかつB_i<=B_jなる(i,j)の数え上げ
    SegmentTree<ll> seg(n,[](ll a,ll b){return a+b;},0ll);

    ll ans=0;
    for(int i=0;i<n;i++){
        int cnt=1;
        while(i+1<n&&vec[i]==vec[i+1]){
            cnt++;
            i++;
        }
        int bi=vec[i].second;
        seg.add(bi,cnt);
        ans+=cnt*seg.query(0,bi+1);
    }
    cout<<ans<<endl;
}