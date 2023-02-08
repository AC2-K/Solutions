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
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    const int N_MAX=2000;
    vector<bitset<N_MAX>> g(n,0);   //g[i][j]:=i->jに行けるか?
    rep(i,m){
        int a,b;
        cin>>a>>b;
        a--,b--;
        g[a][b]=1;
    }
    int q;
    cin>>q;
    vector<int> s(q),t(q);
    rep(i,q){
        cin>>s[i]>>t[i];
        s[i]--,t[i]--;
    }
    vector<int> ans(q,-1);
    rep(k,n){
        rep(i,n){
            if(g[i][k]){
                g[i]|=g[k];
            }
        }
        rep(i,q){
            if(ans[i]!=-1)continue;
            if(g[s[i]][t[i]]&&s[i]<=k&&t[i]<=k){    //行ける。かつ、k以下
                ans[i]=k+1;
            }
        }
    }
    rep(i,q){
        cout<<ans[i]<<'\n';
    }
}