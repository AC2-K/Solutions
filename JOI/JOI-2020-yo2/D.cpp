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
    vector<P> vec;
    int n;
    cin>>n;
    rep(i,n){
        int a,t;
        cin>>a>>t;
        vec.emplace_back(a,t);
    }

    sort(all(vec));

    ll t=max(vec.back().first,vec.back().second);
    ll pos=vec.back().first;

    rep(i,n-2){
        t+=pos-vec[i].first;
        pos=vec[i].first;
        chmax(t,1ll*vec[i].second);
    }
    cout<<t+pos<<endl;
}