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
    int n,a,b,c;
    cin>>n>>a>>b>>c;
    int ans=inf;
    for(int i=0;i<10000&&a*i<=n;i++)for(int j=0;i+j<10000&&i*a+j*b<=n;j++){
        int nn=n-i*a-j*b;
        if((nn)%c==0){
            int k=nn/c;
            chmin(ans,i+j+k);
        }
    }
    cout<<ans<<'\n';
}