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
int main() {
    int n;
    cin>>n;
    vector<int> a(n),b(n),c(n),d(n);
    for(auto&aa:a)cin>>aa;
    for(auto&bb:b)cin>>bb;
    for(auto&cc:c)cin>>cc;
    for(auto&dd:d)cin>>dd;
    sort(all(a)),sort(all(b)),sort(all(c)),sort(all(d));
    vector<vector<int>> aa(n),bb(n),cc(n);
    rep(i,n){
        int it=lower_bound(all(b),a[i])-b.begin();
        if(0<=it&&it<n)aa[i].push_back(it);
        it--;
        if(0<=it&&it<n)aa[i].push_back(it);
    }

    rep(i,n){
        int it=lower_bound(all(c),b[i])-c.begin();
        if(0<=it&&it<n)bb[i].push_back(it);
        it--;
        if(0<=it&&it<n)bb[i].push_back(it);
    }

    rep(i,n){
        int it=lower_bound(all(d),c[i])-d.begin();
        if(0<=it&&it<n)cc[i].push_back(it);
        it--;
        if(0<=it&&it<n)cc[i].push_back(it);
    }

    ll ans=infl;
    rep(i,n)for(auto j:aa[i])for(auto k:bb[j])for(auto l:cc[k]){
        int A=a[i],B=b[j],C=c[k],D=d[l];
        ll mn=min({A,B,C,D});
        ll mx=max({A,B,C,D});
        chmin(ans,mx-mn);  
    }
    cout<<ans<<endl;
}