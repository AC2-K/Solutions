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
    int n,q;
    ll s,t;
    cin>>n>>q>>s>>t;
    vector<ll> a(n+1);
    for(int i=0;i<=n;i++)cin>>a[i];
    vector<ll> d(n+1);
    for(int i=0;i<n;i++){
        d[i]=a[i+1]-a[i];
    }
    auto calc=[&](int pos)-> ll {
        if(pos>=n)return 0;
        
        if(d[pos]>0)return -d[pos]*s;
        else return -d[pos]*t;
    };
    ll now_res=0;
    for(int i=0;i<n;i++)now_res+=calc(i);
    while(q--){
        ll l,r,x;
        cin>>l>>r>>x;
        ll pre=calc(l-1)+calc(r);
        d[l-1]+=x;
        d[r]-=x;
        ll now=calc(l-1)+calc(r);
        ll diff=now-pre;
        now_res+=diff;
        cout<<now_res<<'\n';
    }
}