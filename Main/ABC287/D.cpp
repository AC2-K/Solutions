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
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s,t;
    cin>>s>>t;
    int n=t.size();
    vector<int> front_check(n+1),back_check(n+1);
    front_check[0]=true,back_check[0]=true;  
    rep(i,n){
        front_check[i+1]=front_check[i]&&(s[i]=='?'||t[i]=='?'||s[i]==t[i]);
    }
    reverse(all(s));
    reverse(all(t));
    rep(i,n){
        back_check[i+1]=back_check[i]&&(s[i]=='?'||t[i]=='?'||s[i]==t[i]);
    }

    rep(i,n+1){
        if(front_check[i]&&back_check[n-i])cout<<"Yes\n";
        else cout<<"No\n";
    }
}