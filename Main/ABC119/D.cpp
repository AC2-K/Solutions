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
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a,b,q;
    cin>>a>>b>>q;
    vector<ll> s(a),t(b);
    for(auto&ss:s)cin>>ss;
    for(auto&tt:t)cin>>tt;
    
    while(q--){
        ll x;
        cin>>x;
        auto up1=lower_bound(all(s),x);
        auto down1=upper_bound(all(s),x);

        auto up2=lower_bound(all(t),x);
        auto down2=upper_bound(all(t),x);

        vector<ll> ss,tt;
        if(up1!=s.end())ss.push_back(*up1);
        if(down1!=s.begin())ss.push_back(*prev(down1));

        if(up2!=t.end())tt.push_back(*up2);
        if(down2!=t.begin())tt.push_back(*prev(down2));

        ll ans=infl;
        for(auto p1:ss)for(auto p2:tt){
            chmin(ans,abs(x-p1)+abs(p1-p2));
        }
        swap(ss,tt);
        for(auto p1:ss)for(auto p2:tt){
            chmin(ans,abs(x-p1)+abs(p1-p2));
        }

        cout<<ans<<'\n';
    }
}