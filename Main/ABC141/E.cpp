#include<bits/stdc++.h>
using namespace std;
//cout << fixed << setprecision(10);
 #define rep(i, N)  for(int i=0;i<(N);i++)
#define all(x) (x).begin(),(x).end()
#define popcount(x) __builtin_popcount(x)
using ll = long long;
using ld = long double;
using Graph = vector<vector<int>>;
using P = pair<int, int>;
const int INF = 1e9;
const ll INFL = 1e18;
const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };
template<class T>void chmax(T&x,T y){if(x<y)x=y;}
template<class T>void chmin(T&x,T y){if(x>y)x=y;}
int main() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<vector<int>> dp(n+1,vector<int>(n+1));   //@dp[i][j]:一つ目のsubstrのbackがi,二つ目のsubstrのbackがjとなる時の、substrのlenの最大値
    dp[0][0]=0;
    rep(i,n)rep(j,n){
       if(i>=j)continue;
        if(s[i]==s[j]){
            chmax(dp[i+1][j+1],min(j-i,dp[i][j]+1));    //dp[i][j]は最大でもj-i
        }
    }
    int ans=0;
    rep(i,n+1)rep(j,n+1){
        if(i>=j)continue;
        chmax(ans,dp[i][j]);
    }
    cout<<ans<<endl;
}