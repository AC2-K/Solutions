#include<bits/stdc++.h>
using namespace std;
//cout << fixed << setprecision(10);
#define rep(i, N)  for(int i=0;i<(N);i++)
#define all(x) (x).begin(),(x).end()
#define popcount(x) __builtin_popcount(x)
using ll = long long;
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
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<int> a(n);
    rep(i,n){
        if(s[i]=='J')a[i]=0;
        else if(s[i]=='O')a[i]=1;
        else if(s[i]=='I')a[i]=2;
    }


    int dp[2000][1<<3]; //dp[i][S]:=i日目について、出席者がSとなるような場合の数
    rep(i,2000)rep(j,1<<3)dp[i][j]=0;
    dp[0][1<<0]=1;
    rep(i,n)rep(bit,1<<3)rep(nbit,1<<3){
        if(!(bit&nbit))continue;    //共通部分がないとだめ
        if(!(nbit&(1<<a[i])))continue; //責任者が出席しないのもだめ
        dp[i+1][nbit]+=dp[i][bit];
        dp[i+1][nbit]%=10007;
    }
    /*
    rep(i,n){
        rep(bit,1<<3)cout<<dp[i][bit]<<' ';
        cout<<'\n';
    }
    */

    int ans=0;
    rep(bit,1<<3){
        if(bit&(1<<a[n-1])){
            ans+=dp[n][bit];
            ans%=10007;
        }
    }
    cout<<ans<<endl;
}