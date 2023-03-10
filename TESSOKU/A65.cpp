#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
//#include<atcoder/all>
//using namespace atcoder;
#define rep(i, N)  for(int i=0;i<(N);i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;
using ld = long double;
using Graph = vector<vector<int>>;
using P = pair<int, int>;
const int INF = 1e9;
const ll INFL = 1e18;
const ll MOD = 1e9 + 7;
const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };
int main() {
    int N;
    cin>>N;
    vector<vector<int>> chs(N+1);
    for(int i=2;i<=N;i++){
        int p;
        cin>>p;
        chs[p].push_back(i);
    }
    vector<int> dp(N+1);
    for(int v=N;v>=1;v--){
        for(auto c:chs[v]){
            dp[v]+=(dp[c]+1);
        }
    }
    for(int i=1;i<=N;i++)cout<<dp[i]<<' ';
    cout<<'\n';
}