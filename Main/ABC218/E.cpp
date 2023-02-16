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
class DSU {
private:
    vector<int> par, rank, siz;
    int N;
public:
    DSU(int n) : par(n, -1), rank(n, 0), siz(n, 1), N(n) {}

    int root(int x) {
        if (par[x] == -1)
            return x;
        else
            return par[x] = root(par[x]);
    }
    bool same(int x, int y) {
        return root(x) == root(y);
    }

    bool merge(int x, int y) {
        int rx = root(x), ry = root(y);
        if (rx == ry)
            return false;

        if (rank[rx] < rank[ry])
            swap(rx, ry);
        par[ry] = rx;

        siz[rx] += siz[ry];
        return true;
    }

    int size(int x) {
        return siz[root(x)];
    }
    int connect() {
        int cnt = 0;
        for (int i = 0; i < N; i++)
            if (root(i) == i)
                cnt++;
        return cnt;
    }
};
struct edge{
    int a,b;
    ll cost;
    edge(int a,int b,ll cost):a(a),b(b),cost(cost){ }
};
int main() {
    int n,m;
    cin>>n>>m;
    DSU uf(n);
    vector<edge> e;
    rep(i,m){
        int a,b,c;
        cin>>a>>b>>c;
        a--,b--;
        if(c>0)e.emplace_back(a,b,c);
        else uf.merge(a,b);
    }
    sort(all(e),[&](edge e1,edge e2){return e1.cost<e2.cost;});
    ll ans=0,sum=0;
    for(auto&ee:e){
        sum+=ee.cost;
        if(!uf.same(ee.a,ee.b)){
            ans+=ee.cost;
            uf.merge(ee.a,ee.b);
        }
    }
    cout<<sum-ans<<'\n';
}