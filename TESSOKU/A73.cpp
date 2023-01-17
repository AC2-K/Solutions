#include<bits/stdc++.h>
using namespace std;
//cout << fixed << setprecision(10);
#define rep(i, N)  for(int i=0;i<(N);i++)
#define all(x) (x).begin(),(x).end()
#define popcount(x) __builtin_popcount(x)
using ll = long long;
using ld = long double;
using graph = vector<vector<int>>;
using P = pair<int, ll>;
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
vector<ll> dijkstra(int s,const vector<vector<pair<ll,ll>>>&g){
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
            int nv=nex.first,nc=nex.second;
            if(dist[nv]<dist[vv]+nc)continue;
            dist[nv]=dist[vv]+nc;
            que.emplace(dist[nv],nv);
        }
    }
    return dist;
}
void solve(){
    struct edge
    {
        int to;
        ll cost;
        int tree;   //木が植えられているか
        edge(int a,int b,int c):to(a),cost(b),tree(c){  }

        bool operator>(edge other){
            return this->cost > other.cost;
        }
        bool operator<(edge other){
            return this->cost < other.cost;
        }
    };

    int n,m;
    cin>>n>>m;
    vector<vector<edge>> g(n);
    rep(i,m){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        a--;
        b--;
        g[a].emplace_back(b,c,d);
        g[b].emplace_back(a,c,d);
    }


    vector<ll> cnt(n,0);
    vector<ll> dist(n,infl);
    priority_queue<P,vector<P>,greater<P>> que;
    vector<bool> confirm(n,false);
    dist[0]=0;
    que.emplace(0,0);
    while(!que.empty()){
        auto [c,v]=que.top();
        que.pop();
        if(confirm[v])continue;
        confirm[v]=true;
        for(auto e:g[v]){
            int nex=e.to;
            int nc=e.cost;
            if(dist[nex]<dist[v]+nc)continue;
            else if(dist[nex]==dist[v]+nc){
                chmax(cnt[nex],cnt[v]+e.tree);
            }
            else{
                cnt[nex]=cnt[v]+e.tree;
            }
            dist[nex]=dist[v]+nc;
            que.emplace(dist[nex],nex);
        }
    }

    cout<<dist[n-1]<<' '<<cnt[n-1]<<endl;
}
int main() {
    solve();
}