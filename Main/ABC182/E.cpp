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
    int h,w,n,m;
    cin>>h>>w>>n>>m;
    vector<int> a(n),b(n);
    rep(i,n)cin>>a[i]>>b[i],a[i]--,b[i]--;
    vector<vector<bool>> block(h,vector<bool>(w));
    vector<vector<bool>> tate(h,vector<bool>(w)),yoko(h,vector<bool>(w));
    vector<vector<bool>> lamp(h,vector<bool>(w,false));
    rep(i,m){
        int c,d;
        cin>>c>>d;
        c--,d--;
        block[c][d]=true;
    }
    //縦方向にBFSする
    queue<P> que;
    constexpr int d[]={-1,1};
    rep(i,n){
        que.emplace(a[i],b[i]);
    }

    while(que.size()){
        auto [vi,vj]=que.front();
        que.pop();
        if(tate[vi][vj])continue;
        lamp[vi][vj]=true;
        tate[vi][vj]=true;
        rep(i,2){
            int ni=vi+d[i],nj=vj;
            if(ni<0||ni>=h)continue;
            if(tate[ni][nj])continue;
            if(block[ni][nj])continue;
            que.emplace(ni,nj);
        }
    }
    rep(i,n){
        que.emplace(a[i],b[i]);
    }
    //横方向
    while(que.size()){
        auto [vi,vj]=que.front();
        que.pop();
        if(yoko[vi][vj])continue;
        lamp[vi][vj]=true;
        yoko[vi][vj]=true;
        rep(i,2){
            int ni=vi,nj=vj+d[i];
            if(nj<0||nj>=w)continue;
            if(yoko[ni][nj])continue;
            if(block[ni][nj])continue;
            que.emplace(ni,nj);
        }
    }
    int ans=0;
    rep(i,h)rep(j,w){
        if(lamp[i][j]){
            ans++;
        }
    }
    cout<<ans<<endl;
}