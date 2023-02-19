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
    int color;
    edge(int to,int color):to(to),color(color){ }
};

void solve(){
    int n,m;
    cin>>n>>m;  
    graph g(n);
    vector<int> c(n);
    for(auto&cc:c)cin>>cc;
    rep(i,m){
        int u,v;
        cin>>u>>v;
        u--,v--;
        g[u].push_back(v);
        g[v].push_back(u);
        //g2[n-u-1].emplace_back(n-v-1,c);
        //g2[n-v-1].emplace_back(n-u-1,c);
    }

    queue<P> que;
    que.emplace(0,n-1);
    vector<vector<int>> dist(n,vector<int>(n,inf));
    dist[0][n-1]=0;
    while(!que.empty()){
        int u,v;
        tie(u,v)=que.front();
        que.pop();
        for(auto&nv:g[v])for(auto&nu:g[u]){
            if(c[nv]==c[nu])continue;
            if(dist[nu][nv]!=inf)continue;
            dist[nu][nv]=dist[u][v]+1;
            que.emplace(nu,nv);
        }
    }

    if(dist[n-1][0]>=inf)cout<<-1<<'\n';
    else cout<<dist[n-1][0]<<endl;
}
int main() {
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}