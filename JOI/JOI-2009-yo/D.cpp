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
int main() {
    int w,h;
    cin>>w>>h;
    vector<vector<int>> g(h,vector<int>(w));
    rep(i,h)rep(j,w){
        int a;
        cin>>a;
        g[i][j]=a;
    }
    vector<vector<bool>> vis(h,vector<bool>(w,false));
    function<int(int,int)> dfs=[&](int vi,int vj)-> int {
        int res=1;
        vis[vi][vj]=true;
        rep(i,4){
            int ni=vi+dx[i],nj=vj+dy[i];
            if(ni<0||nj<0||ni>=h||nj>=w)continue;
            if(vis[ni][nj])continue;
            if(g[ni][nj]==0)continue;
            chmax(res,dfs(ni,nj)+1);
        }
        vis[vi][vj]=false;
        return res;
    };
    int ans=0;
    rep(i,h)rep(j,w){
        if(g[i][j]==1){
            chmax(ans,dfs(i,j));
        }
        /*
        rep(ii,h)rep(jj,w){
            vis[i][j]=false;
        }
        */
    }
    cout<<ans<<endl;
}