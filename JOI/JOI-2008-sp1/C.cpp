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
template<class T>inline void chmax(T&x,T y){if(x<y)x=y;}
template<class T>inline void chmin(T&x,T y){if(x>y)x=y;}
int main() {
    int n,m,d,k;
    cin>>n>>m>>d>>k;
    vector<int> x(n),y(n);
    vector<vector<int>> idx(2000,vector<int>(2000,-1));
    rep(i,n){
        cin>>x[i]>>y[i];
        idx[x[i]][y[i]]=i;
    }
    vector<P> dxy;
    for(int dx=-d;dx<=d;dx++)for(int dy=-d;dy<=d;dy++){
        if(dx*dx+dy*dy<=d*d){
            dxy.emplace_back(dx,dy);
        }
    }
    sort(all(dxy));
    dxy.erase(unique(all(dxy)),dxy.end());
    queue<P> que;
    que.emplace(0,0);
    vector<bool> vis(n);
    vis[0]=true;
    int ans=0;
    while(!que.empty()){
        auto [v,c]=que.front();
        que.pop();
        if(k-m+1<=c)ans++;
        if(c==k)continue;
        for(auto [dx,dy]:dxy){
            //cout<<x[v]<<' '<<y[v]<<'\n';
            if(x[v]+dx<0||y[v]+dy<0)continue;
            int nv=idx[x[v]+dx][y[v]+dy];
            if(nv==-1)continue;
            if(vis[nv])continue;
            vis[nv]=true;
            que.emplace(nv,c+1);
        }
    }
    cout<<ans<<endl;
}