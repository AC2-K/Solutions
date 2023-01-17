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
int main() {
    string n;
    cin>>n;
    int siz=n.size();
    ll dp[12][2][12];
    rep(i,12)rep(j,2)rep(k,12)dp[i][j][k]=0;
    //dp[i][flag][j]:=上位i桁みる。nより小さいことが確定(flag==1?していて/していなくて)、さらに1をj個含むような個数

    dp[0][0][0]=1;
    rep(i,siz)rep(flag,2)rep(j,12){
        int c=n[i]-'0';
        rep(nex,10){
            if(nex>c&&flag==0)continue;
            
            int nex_flag=flag;
            if(nex<c)nex_flag=1;

            int nex_j=j;
            if(nex==1)nex_j++;
            if(nex_j>=12)continue;
            dp[i+1][nex_flag][nex_j]+=dp[i][flag][j];
        }
    }

    ll ans=0;
    rep(flag,2)rep(j,12){
        ans+=j*dp[siz][flag][j];
    }

    cout<<ans<<endl;
}