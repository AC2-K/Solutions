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
template<class T>void chmax(T&x,T y){if(x<y)x=y;}
template<class T>void chmin(T&x,T y){if(x>y)x=y;}
int main() {
    int n;
    cin>>n;
    vector<vector<int>> ch(n);
    vector<int> a(n);
    int root=-1;
    rep(i,n){
        int s;
        cin>>s>>a[i];
        s--;
        if(s==-1){
            root=i;
        }else{
            ch[s].push_back(i);
        }
    }
    vector<int> dp(n,-inf);    //dp[v]:=選んだものの中で一番上がvとなるとき、sum aの最大値
    auto rec=[&](auto f,int v)-> int {
        if(dp[v]!=-inf){
            return dp[v];
        }
        //vが葉のとき
        if(ch[v].empty()){
            return dp[v]=a[v];  //選ぶのは確定してる
        }

        //そうじゃないとき

        int res=0;
        for(auto c:ch[v]){
            res+=max(f(f,c),0);
        }

        res+=a[v];
        return dp[v]=res;
    };
    int ans=-inf;
    rep(v,n){
        chmax(ans,rec(rec,v));
    }
    cout<<ans<<endl;
}