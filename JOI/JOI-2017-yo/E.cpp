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
    int h,w;
    cin>>h>>w;
    vector<vector<int>> m(h,vector<int>(w));
    rep(i,h)rep(j,w){
        cin>>m[i][j];
    }
    vector<P> start;
    rep(i,h)rep(j,w){
        bool exists=false;
        rep(k,4){
            int ni=i+dx[k],nj=j+dy[k];
            if(ni<0||nj<0||ni>=h||nj>=w){
                continue;
            }
            //さらに流すことができるか?
            if(m[ni][nj]<m[i][j]){
                exists=true;
            }
        }

        if(!exists){
            //cout<<m[i][j]<<' ';
            start.emplace_back(i,j);
        }
    }

    vector<vector<int>> cnt(h,vector<int>(w));
    for(const auto&s:start){
        vector<vector<bool>> vis(h,vector<bool>(w,false));
        queue<P> que;
        que.emplace(s);
        cnt[s.first][s.second]++;
        vis[s.first][s.second]=true;
        while(que.size()){
            const auto&[vi,vj]=que.front();
            que.pop();


            rep(i,4){
                int ni=vi+dx[i],nj=vj+dy[i];

                if(ni<0||nj<0||ni>=h||nj>=w){
                    continue;
                }
                if(m[ni][nj]<=m[vi][vj]){
                    continue;
                }
                if(vis[ni][nj]){
                    continue;
                }
                vis[ni][nj]=true;
                cnt[ni][nj]++;
                if(cnt[ni][nj]<=2){
                    que.emplace(ni,nj);
                }
            }
        }
    }

    int ans=0;
    rep(i,h)rep(j,w){
        if(cnt[i][j]>=2){
            //cout<<m[i][j]<<'\n';
            ans++;
        }
    }
    cout<<ans<<'\n';
}