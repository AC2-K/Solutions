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
vector<ll> dijkstra(int s,const vector<vector<pair<ll,ll>>>&g){
    int n=g.size();
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> que;
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
            int nv=nex.first,nc=nex.second;
            if(dist[nv]<dist[vv]+nc)continue;
            dist[nv]=dist[vv]+nc;
            que.emplace(dist[nv],nv);
        }
    }
    return dist;
}
int main() {
    ll n,m,k,s;
    cin>>n>>m>>k>>s;
    ll p,q;
    cin>>p>>q;
    vector<int> c(k);
    for(auto&cc:c){
        cin>>cc;
        cc--;
    }

    graph g(n);
    rep(i,m){
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<int> dist(n,-1);
    queue<int> que;
    for(auto&cc:c){
        dist[cc]=0;
        que.push(cc);
    }

    while(!que.empty()){
        auto v=que.front();
        que.pop();
        for(auto nv:g[v]){
            if(dist[nv]!=-1)continue;
            dist[nv]=dist[v]+1;
            que.push(nv);
        }
    }

    vector<bool> is_danger(n,false);
    rep(v,n){
        if(dist[v]<=s){
            is_danger[v]=true;
        }
    }

    vector<vector<pair<ll,ll>>> g2(n);
    rep(v,n){
        for(auto to:g[v]){
            if(dist[to]==0)continue;
            ll cost=infl;
            if(!is_danger[to])cost=p;
            else cost=q;
            if(to==n-1)cost=0;
            g2[v].emplace_back(to,cost);
        }
    }

    auto res=dijkstra(0,g2);
    cout<<res[n-1]<<endl;
}