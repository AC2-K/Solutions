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
    int h,w;
    cin>>h>>w;
    vector<string> s(h);
    for(auto&ss:s){
        cin>>ss;
    }
    vector<vector<int>> tate(w),yoko(h);
    rep(i,h)rep(j,w){
        if(s[i][j]=='#'){
            tate[j].emplace_back(i);
            yoko[i].emplace_back(j);
        }
    }
    rep(i,w){
        tate[i].emplace_back(h);
        tate[i].emplace_back(-1);
    }
    rep(i,h){
        yoko[i].emplace_back(w);
        yoko[i].emplace_back(-1);
    }
    for(auto&t:tate)sort(all(t));
    for(auto&y:yoko)sort(all(y));
    int ans=0;
    rep(i,h)rep(j,w){
        if(s[i][j]=='#')continue;
        int s=0;
        auto up=upper_bound(all(tate[j]),i);
        auto down=prev(up);
        s+=(*up)-(*down)-1;

        up=upper_bound(all(yoko[i]),j);
        down=prev(up);
        s+=(*up)-(*down)-1;
        s--;
        chmax(ans,s);
    }
    cout<<ans<<endl;
}