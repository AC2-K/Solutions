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

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string x;
    int n;
    cin>>x>>n;
    constexpr int alphabet_num='z'-'a'+1;
    vector<int> idx(alphabet_num);
    rep(i,x.size()){
        idx[x[i]-'a']=i;
    }
    vector<string> s(n);
    for(auto&ss:s){
        cin>>ss;
    }
    sort(all(s),[&](string s1,string s2){
        rep(i,min(s1.size(),s2.size())){
            if(s1[i]!=s2[i])return idx[s1[i]-'a']<idx[s2[i]-'a'];
        }
        return s1.size()<s2.size();
    });
    for(auto&ss:s){
        cout<<ss<<'\n';
    }
}