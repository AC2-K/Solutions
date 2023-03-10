#include<bits/stdc++.h>
using namespace std;
//cout << fixed << setprecision(10);
#define rep(i, N)  for(int i=0;i<(N);i++)
#define all(x) (x).begin(),(x).end()
#define popcount(x) __builtin_popcount(x)
using ll = long long;
using ld = long double;
using graph = vector<vector<int>>;
using P = pair<ll, ll>;
const int inf = 1e9;
const ll infl = 1e18;
const ld eps = ld(0.000000001);
const long double pi = acos(-1);
const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };
/*
template<class T>using v=vector<T>;
template<class T>using vv=v<v<T>>;
template<class T>using vvv=v<vv<T>>;
template<class T>using vvvv=v<vvv<T>>;
*/
template<class T>void chmax(T&x,T y){if(x<y)x=y;}
template<class T>void chmin(T&x,T y){if(x>y)x=y;}
int main() {
    int n;
    cin>>n;
    ll k;
    cin>>k;
    //操作順は関係ない
    vector<P> ab(n);    //<-firstにval,secondにcntを突っ込む
    for(auto&e:ab){
        cin>>e.first>>e.second;
    }
    sort(all(ab));
    vector<ll> cnt(n+1);    //cnt[i]:=i回操作したとき、すでに入っている個数
    rep(i,n){
        cnt[i+1]=cnt[i]+ab[i].second;
    }

    ll lim=lower_bound(all(cnt),k)-cnt.begin();
    cout<<ab[lim-1].first<<endl;
}