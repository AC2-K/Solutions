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
const ld eps = 1e-6;
const long double pi = acos(-1);
const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };
template<class T,class U>void chmax(T&x,U y){if(x<y)x=y;}
template<class T,class U>void chmin(T&x,U y){if(x>y)x=y;}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto&aa:a)cin>>aa;
    sort(all(a));
    int q;
    cin>>q;
    while(q--){
        int b;
        cin>>b;
        auto it=lower_bound(all(a),b);
        ll ans=infl;
        if(it!=a.end())chmin(ans,abs((*it)-b));
        if(it!=a.begin())chmin(ans,abs(*prev(it)-b));
        cout<<ans<<endl;
    }
}