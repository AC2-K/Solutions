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
    int n;
    cin>>n;
    vector<vector<int>> a(n,vector<int>(n));
    rep(i,n)rep(j,n){
        cin>>a[i][j];
    }
    int m;
    cin>>m;
    vector<vector<bool>> is_ok(n,vector<bool>(n,true));
    rep(i,m){
        int x,y;
        cin>>x>>y;
        x--,y--;
        is_ok[x][y]=false;
        is_ok[y][x]=false;
    }
    vector<int> idx(n);
    iota(all(idx),0);
    ll ans=infl;
    do{
        bool flag=false;
        rep(i,n-1){
            if(!is_ok[idx[i]][idx[i+1]]){
                flag=true;
            }
        }
        if(flag){
            continue;
        }
        ll time=0;
        rep(i,n){
            time+=a[idx[i]][i];
        }
        chmin(ans,time);
    }while(next_permutation(all(idx)));
    cout<<(ans>=infl?-1:ans)<<'\n';
}