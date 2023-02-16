#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
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
int main() {
    int n,m;
    cin>>n>>m;
    scc_graph g(n);
    graph rev(n);
    rep(i,m){
        int u,v;
        cin>>u>>v;
        u--,v--;
        g.add_edge(u,v);
        rev[v].push_back(u);
    }
    auto res=g.scc();
    queue<int> que;
    vector<bool> vis(n,false);
    for(const auto&el:res)if(el.size()>=2)for(const auto&v:el){
        vis[v]=true;
        que.emplace(v);
    }

    while(!que.empty()){
        int v=que.front();
        que.pop();
        for(const auto&pre:rev[v])if(!vis[pre]){
            vis[pre]=true;
            que.emplace(pre);
        }
    }

    int ans=0;
    for(const auto&v:vis)if(v){
        ans++;
    }
    cout<<ans<<'\n';
}