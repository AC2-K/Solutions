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
    int n,m,d;
    cin>>n>>m>>d;
    vector<P> vec(n);
    rep(i,n){
        cin>>vec[i].first>>vec[i].second;
    }
    sort(all(vec));
    vector<int> x(n),v(n);
    rep(i,n){
        tie(x[i],v[i])=vec[i];
    }
    //全部lim以上としたとき、m個選べるか?
    auto is_ok=[&](int lim)-> bool {
        int cnt=0;
        int prev=-inf;
        rep(i,n){
            if(x[i]-prev>=d&&v[i]>=lim){
                cnt++;
                prev=x[i];
            }
        }
        return cnt>=m;
    };

    int ng=*max_element(all(v))+1;
    int ok=*min_element(all(v));
    if(!is_ok(ok)){
        cout<<-1<<endl;
        return 0;
    }

    while(ok+1!=ng){
        int md=(ok+ng)>>1;
        if(is_ok(md))ok=md;
        else ng=md;
    }
    cout<<ok<<endl;
}