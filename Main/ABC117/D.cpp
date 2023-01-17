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
const ld eps = ld(0.000000001);
const long double pi = acos(-1);
const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };
template<class T>void chmax(T&x,T y){if(x<y)x=y;}
template<class T>void chmin(T&x,T y){if(x>y)x=y;}
ll dp[61][2];   //dp[i][flag]:=上位i bit が決定していて、k以下であることが確定(flag==1?している/していない)ような状況について、f(x)のmax
int main() {
    ll n,k;
    cin>>n>>k;
    vector<ll> a(n);
    for(auto&aa:a)cin>>aa;

    rep(i,61)rep(j,2)dp[i][j]=-infl;
    dp[0][0]=0;
    rep(i,60)rep(flag,2)if(dp[i][flag]>=0){
        int d=59-i;
        ll bit=1LL<<d;

        ll zero=0;
        ll one=0;
        for(auto aa:a){
            if(aa&bit)one++;
            else zero++;
        }

        int nex_flag=flag;
        if(k&bit)nex_flag=1;

        //次に0をいれる
        chmax(dp[i+1][nex_flag],dp[i][flag]+one*bit);
        //次に1を入れる
        if((k&bit)==0 && flag==0)continue;
        chmax(dp[i+1][flag],dp[i][flag]+zero*bit);
    }

    cout<<max(dp[60][0],dp[60][1])<<endl;
}