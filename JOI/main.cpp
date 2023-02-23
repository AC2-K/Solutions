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
    int h,w,k;
    cin>>h>>w>>k;
    vector<vector<bool>> button(n,vector<bool>(m,false));
    rep(i,k){
        int x,y;
        cin>>x>>y;
        x--,y--;
        button[y][x]=true;
    }
    struct state
    {
        int vi,vj;
        bool pushed;
        state(int vi,int vj,bool pushed):vi(vi),vj(vj),pushed(pushed){ }
    };
    

    queue<state> q;
    vector<vector<vector<int>>> dist(n,vector<vector<int>>(m,vector<int>(2,inf)));;
    dist[0][0][0]=true; //dist[vi][vj][fl]:=(vi,vj)に(fl:反転した状態で)到達するまでに必要な経路長
    q.emplace(0,0,0);


    const int d[]={1,-1};
    while(q.size()){
        auto&[vi,vj,c]=q.front();
        q.pop();
        rep(i,2){
            int ni=vi+d[i],nj=vj;
            if(ni<0||nj<0||ni>=h||nj>=w){
                continue;
            }
            if(dist[ni][nj][c+1]!=inf){
                continue;
            }
            if(c&1)continue;
            dist[ni][nj][c]=dist[vi][vj][c]+1;
            q.emplace(ni,nj,c);
        }
        rep(i,2){
            int ni=vi,nj=vj+d[i];
            if(ni<0||nj<0||ni>=h||nj>=w){
                continue;
            }
            if(dist[ni][nj][c+1]!=inf){
                continue;
            }
            if(!(c&1))continue;
            dist[ni][nj][c]=dist[vi][vj][c]+1;
            q.emplace(ni,nj,c);
        }


        if(!button[vi][vj]){
            continue;
        }
        

        int nc=(c+1)&1;
        rep(i,2){
            int ni=vi+d[i],nj=vj;
            if(ni<0||nj<0||ni>=h||nj>=w){
                continue;
            }
            if(dist[ni][nj][nc]!=inf){
                continue;
            }
            if(nc&1)continue;
            dist[ni][nj][nc]=dist[vi][vj][c]+2;
            q.emplace(ni,nj,nc);
        }
        rep(i,2){
            int ni=vi,nj=vj+d[i];
            if(ni<0||nj<0||ni>=h||nj>=w){
                continue;
            }
            if(dist[ni][nj][nc]!=inf){
                continue;
            }
            if(!(nc&1))continue;
            dist[ni][nj][nc]=dist[vi][vj][c]+2;
            q.emplace(ni,nj,nc);
        }
    }
}