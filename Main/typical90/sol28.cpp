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
    const int H_MAX=1e3;
    const int W_MAX=1e3;
    vector<vector<int>> sums(H_MAX+1,vector<int>(W_MAX+1));

    int n;
    cin>>n;
    rep(i,n){
        int lx,ly,rx,ry;
        cin>>lx>>ly>>rx>>ry;
        sums[lx][ly]++;
        sums[lx][ry]--;
        sums[rx][ly]--;
        sums[rx][ry]++;
    }
    for(int i=0;i<=H_MAX;i++)for(int j=1;j<=W_MAX;j++){
        sums[i][j]+=sums[i][j-1];
    }
    for(int j=0;j<=W_MAX;j++)for(int i=1;i<=H_MAX;i++){
        sums[i][j]+=sums[i-1][j];
    }
    map<int,int> cnt;
    rep(i,H_MAX+1)rep(j,W_MAX+1){
        cnt[sums[i][j]]++;
    }

    for(int k=1;k<=n;k++){
        cout<<cnt[k]<<'\n';
    }
}