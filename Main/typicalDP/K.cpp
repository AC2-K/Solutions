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
int main() {
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(auto&aa:a)cin>>aa;
    vector<bool> dp(k+1,false);     //@dp[i]:残りiこの状態で勝てるか?
    for(int i=0;i<=k;i++){
        if(dp[i])continue;
        for(auto aa:a){
            if(i+aa>k)continue;
            dp[i+aa]=true;
        }
    }
    if(dp[k])cout<<"First"<<endl;
    else cout<<"Second"<<endl;
}