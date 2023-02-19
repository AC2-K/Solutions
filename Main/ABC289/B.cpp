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


int main() {
    int n,m;
    cin>>n>>m;
    DSU dsu(n);
    rep(i,m){
        int a;
        cin>>a;
        a--;
        dsu.merge(a,a+1);
    }

    vector<bool> vis(n);    //まだ見てない奴
    while(true){
        int x=-1;
        rep(v,n){
            if(!vis[v]){
                x=v;
                break;
            }
        }
        if(x==-1){
            break;
        }

        for(int v=n-1;v>=0;v--){
            if(dsu.same(x,v)){
                cout<<v+1<<'\n';
                vis[v]=true;
            }
        }
    }
}