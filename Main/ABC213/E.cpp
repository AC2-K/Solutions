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
    ios::sync_with_stdio(false);
    cin.tie(0);
    int h,w;
    cin>>h>>w;
    vector<string> s(h);
    for(auto&ss:s){
        cin>>ss;
    }
    deque<P> que;
    vector<vector<int>> dist(h,vector<int>(w,-1));
    dist[0][0]=0;
    que.emplace_back(0,0);

    while(!que.empty()){
        auto [vi,vj]=que.front();
        que.pop_front();
        rep(i,4){
            int ni=vi+dx[i];
            int nj=vj+dy[i];
            if(ni<0||nj<0||ni>=h||nj>=w)continue;
            if(dist[ni][nj]!=-1)continue;
            if(s[ni][nj]=='#')continue;
            dist[ni][nj]=dist[vi][vj];
            que.emplace_front(ni,nj);
        }

        for(int ni=vi-2;ni<=vi+2;ni++)for(int nj=vj-2;nj<=vj+2;nj++){
            if(ni==vi-2&&nj==vj-2)continue;
            if(ni==vi-2&&nj==vj+2)continue;
            if(ni==vi+2&&nj==vj-2)continue;
            if(ni==vi+2&&nj==vj+2)continue;
            
            if(ni<0||nj<0||ni>=h||nj>=w)continue;
            if(dist[ni][nj]!=-1)continue;
            if(s[ni][nj]=='.')continue;
            dist[ni][nj]=dist[vi][vj]+1;
            que.emplace_back(ni,nj);
        }
    }
    cout<<dist[h-1][w-1]<<endl;
}