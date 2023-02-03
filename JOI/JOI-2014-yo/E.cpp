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
struct edge{
    int to;
    ll cost;
    edge(int to,ll cost):to(to),cost(cost){ }
};

vector<ll> dijkstra(int s,const vector<vector<edge>>&g){
    int n=g.size();
    priority_queue<P,vector<P>,greater<P>> que;
    que.emplace(0,s);
    vector<ll> dist(n,infl);
    vector<bool> confirm(n,false);
    dist[s]=0;
    while(!que.empty()){
        auto T=que.top();
        que.pop();
        int vc=T.first,vv=T.second;
        if(confirm[vv])continue;
        confirm[vv]=true;
        for(auto nex:g[vv]){
            int nv=nex.to,nc=nex.cost;
            if(dist[nv]<=dist[vv]+nc)continue;
            dist[nv]=dist[vv]+nc;
            que.emplace(dist[nv],nv);
        }
    }
    return dist;
}
int main() {
    int n,k;
    cin>>n>>k;
    graph g(n);
    vector<int> c(n),r(n);
    rep(i,n){
        cin>>c[i]>>r[i];
    }

    rep(i,k){
        int a,b;
        cin>>a>>b;
        a--,b--;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    vector<vector<edge>> G(n);
    rep(v,n){
        queue<int> que;
        que.push(v);
        vector<int> dist(n,inf);
        dist[v]=0;
        while(que.size()){
            int u=que.front();
            que.pop();
            for(auto nex:g[u]){
                if(dist[nex]<inf)continue;
                dist[nex]=dist[u]+1;
                que.push(nex);
            }
        }
        rep(u,n){
            if(u==v)continue;
            if(dist[u]<=r[v]){
                G[v].emplace_back(u,c[v]);
            }
        }
    }

    auto res=dijkstra(0,G);
    cout<<res[n-1]<<endl;
}