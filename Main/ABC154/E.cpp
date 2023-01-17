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

ll dp[110][2][5];    //dp[i][flag][j]:=先頭i桁見る。現時点でnより小さいのを入れたことが...(flag==0?していない/している)ようなものであって、かつ0がj個含まれるようなものの個数
int main() {
    string n;
    cin>>n;
    int siz=n.size();
    int k;
    cin>>k;
    dp[0][0][0]=1;
    rep(dgt,siz)rep(flag,2)rep(j,k+1){
        int next_digit=n[dgt]-'0';
        rep(nxt,10){
            if(next_digit<nxt&&flag==0)continue;

            int flag2=flag;
            int j2=j;
            if(nxt<next_digit)flag2=1;
            if(nxt!=0)j2++;
            dp[dgt+1][flag2][j2]+=dp[dgt][flag][j];
        }
    }
    cout<<dp[siz][0][k]+dp[siz][1][k]<<'\n';
}