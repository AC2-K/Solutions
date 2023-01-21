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
template<class T>void chmax(T&x,T y){if(x<y)x=y;}
template<class T>void chmin(T&x,T y){if(x>y)x=y;}
struct Edge
{
    int to;
    int id;

    Edge(int to,int id):to(to),id(id){    }
};

int main() {
    int n,m;
    cin>>n>>m;
    vector<vector<Edge>> g(n);
    vector<vector<Edge>> rev(n);
    rep(i,m){
        int v,u;
        cin>>v>>u;
        v--;
        u--;
        g[v].emplace_back(u,i);
        rev[u].emplace_back(v,i);
    }
    //とりあえず、一回BFSする。
    vector<int> dist(n,inf);
    queue<int> que;
    dist[0]=0;
    que.push(0);
    while(!que.empty()){
        int v=que.front();
        que.pop();
        for(auto ne:g[v]){
            int nv=ne.to;
            if(dist[nv]!=inf)continue;
            dist[nv]=dist[v]+1;
            que.push(nv);
        }
    } 
    //そもそも到達できないとき
    if(dist[n-1]==inf){
        rep(i,m){
            cout<<-1<<'\n';
        }
        exit(0);
    }

    //使う辺の復元
    int cur=n-1;
    set<int> use_edges;
    while(cur!=0){
        for(auto pe:rev[cur]){
            if(dist[cur]!=dist[pe.to]+1)continue;
            use_edges.insert(pe.id);
            cur=pe.to;
            break;
        }
    }

    rep(e,m){
        if(!use_edges.count(e)){
            cout<<dist[n-1]<<'\n';
            continue;
        }

        queue<int> q;
        vector<int> d(n,inf);

        q.push(0);
        d[0]=0;
        while(!q.empty()){
            int v=q.front();
            q.pop();
            
            for(auto ne:g[v]){
                if(ne.id==e)continue;

                int nv=ne.to;
                if(d[nv]!=inf)continue;

                d[nv]=d[v]+1;
                q.push(nv);
            }
        }

        if(d[n-1]>=inf)cout<<-1<<'\n';
        else cout<<d[n-1]<<'\n';
    }
}