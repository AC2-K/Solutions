#include<bits/stdc++.h>
using namespace std;
//cout << fixed << setprecision(10);
#define rep(i, N)  for(int i=0;i<(N);i++)
#define all(x) (x).begin(),(x).end()
#define popcount(x) __builtin_popcount(x)
using ll = long long;
using ld = long double;
using graph = vector<vector<int>>;
using P = pair<int, int>;
const int INF = 1e9;
const ll INFL = 1e18;
const ld eps = ld(0.000000001);
const long double pi = 3.141592653589793;
const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };
/*
template<class T>using v=vector<T>;
template<class T>using vv=v<v<T>>;
template<class T>using vvv=v<vv<T>>;
template<class T>using vvvv=v<vvv<T>>;
*/
template<class T>void chmax(T&x,T y){if(x<y)x=y;}
template<class T>void chmin(T&x,T y){if(x>y)x=y;}
int main() {
    int n,m;
    scanf("%d %d",&n,&m);
    graph g(n);
    rep(i,m){
        int a,b;
        scanf("%d %d",&a,&b);
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    int q;
    scanf("%d",&q);
    vector<int> dist(n,-1);
    while(q--){
        int x,k;
        cin>>x>>k;
        x--;
        queue<int> que;
        dist[x]=0;
        que.push(x);
        vector<int> vis;
        ll ans=0;
        while(!que.empty()){
            auto v=que.front();que.pop();
            vis.push_back(v);
            if(dist[v]==k)continue;

            for(auto nex:g[v]){
                if(dist[nex]!=-1)continue;
                dist[nex]=dist[v]+1;
                que.push(nex);
            }
        }
        for(auto v:vis){
            ans+=(v+1);
            dist[v]=-1;
        }
        printf("%d\n",ans);
    }
}