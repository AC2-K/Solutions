#include<bits/stdc++.h>
using namespace std;
//cout << fixed << setprecision(10);
#define rep(i, N)  for(int i=0;i<(N);i++)
#define all(x) (x).begin(),(x).end()
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
int N, A[303], C[4];
double dp[303][303][303];
int main() {
    cin>>N;
    rep(i,N)cin>>A[i];
    rep(i,N)C[A[i]]++;
    rep(c3,N+1)rep(c2,N+1)rep(c1,N+1){
        int S=c1+c2+c3;
        if(S==0)continue;
        dp[c1][c2][c3]=1.0*N/S;
        if (c1) dp[c1][c2][c3] += dp[c1 - 1][c2][c3] * c1 / S;
        if (c2) dp[c1][c2][c3] += dp[c1 + 1][c2 - 1][c3] * c2 / S;
        if (c3) dp[c1][c2][c3] += dp[c1][c2 + 1][c3 - 1] * c3 / S;
    }
    printf("%.10f\n",dp[C[1]][C[2]][C[3]]);
}