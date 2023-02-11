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
    int n,m;
    cin>>n>>m;
    vector<int> s(n),t(m);
    for(auto&ss:s){
        char c;
        cin>>c;
        if(c=='J')ss=0;
        else if(c=='O')ss=1;
        else ss=2;
    }

    for(auto&ss:t){
        char c;
        cin>>c;
        if(c=='J')ss=0;
        else if(c=='O')ss=1;
        else ss=2;
    }

    int dp[2010][2010][3];
    dp[0][0][0]=true,dp[0][0][1]=true,dp[0][0][2]=true;
    rep(i,n+1)rep(j,m+1)rep(k,3){
        if(!dp[i][j][k])continue;
        if(i<n&&s[i]!=k){
            dp[i+1][j][s[i]]=true;
        }
        if(j<n&&t[i]!=k){
            dp[i][j+1][t[i]]=true;
        }
    }
    int ans=0;
    rep(i,n+1)rep(j,m+1)rep(k,3){
        if(dp[i][j][k]){
            chmax(ans,i+j);
        }
    }
    cout<<ans<<endl;
}