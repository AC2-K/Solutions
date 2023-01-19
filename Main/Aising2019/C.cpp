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
int main() {
    int h,w;
    cin>>h>>w;
    vector<string> s(h);
    for(auto&ss:s)cin>>ss;
    vector<vector<bool>> vis(h,vector<bool>(w,false));
    ll ans=0;
    rep(si,h)rep(sj,w){
        if(vis[si][sj])continue;
        queue<P> que;
        int black=0,white=0;
        que.emplace(si,sj);
        while(!que.empty()){
            auto [vi,vj]=que.front();
            que.pop();

            if(s[vi][vj]=='#')black++;
            else white++;

            rep(i,4){
                int ni=vi+dx[i];
                int nj=vj+dy[i];
                if(ni<0||nj<0||ni>=h||nj>=w)continue;
                if(vis[ni][nj])continue;
                if(s[ni][nj]==s[vi][vj])continue;
                vis[ni][nj]=true;
                que.emplace(ni,nj);
            }
        }
        ans+=1ll*black*white;
    }
    cout<<ans<<endl;
}