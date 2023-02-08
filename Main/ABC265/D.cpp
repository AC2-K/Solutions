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
    ll p,q,r;
    cin>>n>>p>>q>>r;
    vector<int> a(n);
    for(auto&aa:a){
        cin>>aa;
    }
    vector<ll> sum(n+1);
    rep(i,n){
        sum[i+1]=sum[i]+a[i];
    }
    rep(x,n+1){
        auto it=lower_bound(sum.begin()+x,sum.end(),p+sum[x]);
        if(it==sum.end()||(*it)!=p+sum[x]){
            continue;
        }
        int y=it-sum.begin();
        it=lower_bound(sum.begin()+y,sum.end(),q+sum[y]);
        if(it==sum.end()||(*it)!=q+sum[y]){
            continue;
        }

        int z=it-sum.begin();

        it=lower_bound(sum.begin()+z,sum.end(),r+sum[z]);
        if(it==sum.end()||(*it)!=r+sum[z]){
            continue;
        }

        cout<<"Yes\n";
        return 0;
    }
    cout<<"No\n";
}