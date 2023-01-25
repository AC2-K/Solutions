#include<bits/stdc++.h>
using namespace std;
#define rep(i, N)  for(int i=0;i<(N);i++)
#define all(x) (x).begin(),(x).end()
#define popcount(x) __builtin_popcount(x)
using ll = long long;
using i128=__int128_t;
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
int main() {
    int n;
    cin>>n;
    graph g(n);
    rep(i,n-1){
        int v,u;
        cin>>v>>u;
        v--;u--;
        g[v].emplace_back(u);
        g[u].emplace_back(v);
    }
    vector<bool> vis(n);
    vector<int> dist(n);
    auto dfs=[&](auto f,int v,int par=-1)-> void {
        vis[v]=true;

        for(auto nex:g[v]){
            if(nex==par)continue;
            if(vis[nex])continue;
            dist[nex]=dist[v]+1;
            f(f,nex,v);
        }
    };
    dfs(dfs,0);
    int now_max=0;
    int s=0;
    rep(v,n){
        if(dist[v]>now_max){
            s=v;
            now_max=dist[v];
        }
    }

    vis.assign(n,false);
    dist.assign(n,0);

    dfs(dfs,s);
    

    int d=*max_element(all(dist));
    cout<<d+1<<endl;
}