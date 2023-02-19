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
template<typename T = ll, bool is_max = false>
class ConvexHullTrick {
    class line {
    public:
        T a, b;
        bool is_query;
        mutable T nxt_a, nxt_b;
        mutable bool has_nxt;
        T get(T x)const { return a * x + b; }
        T get_nxt(T x)const { return nxt_a * x + nxt_b; }
        line() = default;
        line(T a, T b, bool query = false) :a(a), b(b), is_query(query), has_nxt(false) {}
        friend bool operator<(const line& l, const line& r) {
            if (l.is_query) {
                if (!r.has_nxt)return true;
                return r.get(l.a) < r.get_nxt(l.a);
            }
            if (r.is_query) {
                if (!l.has_nxt)return false;
                return l.get(r.a) > l.get_nxt(r.a);
            }
            return l.a == r.a ? l.b < r.b : l.a < r.a;
        }
    };

    set<line> ls;
    bool is_needed(const typename set<line>::iterator& it) {
        //set<line> ls;
        if (it != ls.begin() && it->a == prev(it)->a)return it->b < prev(it)->b;
        if (next(it) != ls.end() && it->a == next(it)->a)return it->b < next(it)->b;
        if (it == ls.begin() || next(it) == ls.end())return true;
        return 1.*(it->b - prev(it)->b) * (next(it)->a - it->a) < 1.*(it->b - next(it)->b) * (prev(it)->a - it->a);	//精度で死なないように気を付ける!!!
    }

public:
    ConvexHullTrick() = default;
    void add(T a,T b) {
        auto it = ls.emplace(is_max ? -a : a, is_max ? -b : b).first;
        if (!is_needed(it)) {
            ls.erase(it);
            return;
        }
        while (it != ls.begin() && !is_needed(prev(it)))ls.erase(prev(it));
        while (next(it) != ls.end() && !is_needed(next(it)))ls.erase(next(it));
        if (it != ls.begin()) {
            prev(it)->has_nxt = true;
            prev(it)->nxt_a = it->a;
            prev(it)->nxt_b = it->b;
        }
        if (it != prev(ls.end())) {
            it->has_nxt = true;
            it->nxt_a = next(it)->a;
            it->nxt_b = next(it)->b;
        }
    }
    T operator()(T x) const {
        const auto& it = ls.lower_bound(line(x, 0, true));

        if (is_max) {	
            return -it->a * x - it->b;
        }
        else {
            return it->a * x + it->b;
        }
    }
};
int main() {
    ConvexHullTrick<ll> cht;
    int n;
    double c;
    cin>>n>>c;
    vector<ll> h(n);
    for(auto&hh:h){
        cin>>hh;
    }
    vector<ll> dp(n);
    dp[0]=0;
    cht.add(-2*h[0],c+h[0]*h[0]+dp[0]);

    for(int i=1;i<n;i++){
        dp[i]=cht(h[i])+h[i]*h[i];
        cht.add(-2*h[i],c+h[i]*h[i]+dp[i]);
    }
    cout<<dp[n-1]<<'\n';
}