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
const int inf = 1e9;
const ll infl = 1e18;
const ld eps = ld(0.000000001);
const long double pi = acos(-1);
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
    cin>>n>>m;
    graph g(n);
    rep(i,m){
        int s,t;
        cin>>s>>t;
        s--;
        t--;
        g[s].push_back(t);
        g[t].push_back(s);
    }
    vector<bool> vis(n,false);
    vis[0]=true;
    ll ans=1;
    const int MAX=1e6;
    auto dfs=[&](auto f,int v)-> void {
        vis[v]=true;
        ans++;
        if(ans>=MAX){
            cout<<MAX<<endl;
            exit(0);
        }
        for(auto nex:g[v]){
            if(vis[nex])continue;
            f(f,nex);
        }
        vis[v]=false;
    };

    vis[0]=true;
    for(auto nex:g[0]){
        dfs(dfs,nex);
    }
    cout<<ans<<endl;
}