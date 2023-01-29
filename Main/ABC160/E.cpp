
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
    int x,y;
    cin>>x>>y;
    int a,b,c;
    cin>>a>>b>>c;
    vector<ll> p(a),q(b),r(c);
    for(auto&pp:p)cin>>pp;
    for(auto&qq:q)cin>>qq;
    for(auto&rr:r)cin>>rr;
    sort(all(p),greater<>());
    sort(all(q),greater<>());
    sort(all(r),greater<>());
    p.resize(x),q.resize(y);

    vector<ll> vec;
    for(auto&pp:p)vec.push_back(pp);
    for(auto&qq:q)vec.push_back(qq);
    for(auto&rr:r)vec.push_back(rr);
    sort(all(vec),greater<>());
    ll ans=0;
    rep(i,x+y)ans+=vec[i];
    cout<<ans<<endl;
}