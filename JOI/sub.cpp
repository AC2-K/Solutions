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
    int n;
    string s;
    cin>>n>>s;
    vector<int> sum_j(n+1),sum_o(n+1),sum_i(n+1);
    rep(i,n){
        sum_j[i+1]=sum_j[i];
        sum_o[i+1]=sum_o[i];
        sum_i[i+1]=sum_i[i];

        if(s[i]=='J')sum_j[i+1]++;
        else if(s[i]=='O')sum_o[i+1]++;
        else sum_i[i+1]++;
    }
    ll mx = -1;

    //'O'を挿入する
    rep(i,n){
        int cnt_j=sum_j[i+1];
        int cnt_i=sum_i[n]-sum_i[i+1];

        chmax(mx,1ll*cnt_j*cnt_i);
    }
    //'J' をpush frontする
    
    ll cnt=0;
    rep(i,n){   //'o'
    
        if(s[i]=='O'){
            cnt+=sum_i[n]-sum_i[i+1];
        }
    }
    
    chmax(mx,cnt);
    //'I'をpush backする
    cnt=0;
    rep(i,n){   //'o'
        if(s[i]=='O'){
            cnt+=sum_j[i];
        }
    }
    chmax(mx,cnt);


    //元の個数
    vector<vector<ll>> dp(n+1,vector<ll>(4));
    dp[0][0]=1;
    const string joi="JOI";
    rep(i,n)rep(j,4){
        dp[i+1][j]+=dp[i][j];
        if(j<3&&s[i]==joi[j]){
            dp[i+1][j+1]+=dp[i][j];
        }
    }
    cout<<dp[n][3]+mx<<'\n';
}