
#include<bits/stdc++.h>
#pragma onece
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
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<vector<edge>> g(n);
    rep(i,m){
        ll a,b,c;
        cin>>a>>b>>c;
        a--;
        b--;
        g[a].emplace_back(b,c);
        g[b].emplace_back(a,c);
    }
    auto res=dijkstra(0,g);
    rep(v,n){
        if(res[v]>=infl)cout<<-1<<'\n';
        else cout<<res[v]<<'\n';
    }
}