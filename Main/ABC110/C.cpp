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
    string s,t;
    cin>>s>>t;
    int n=s.size();
    vector<int> fs(n),ft(n);
    map<char,int> mp_s,mp_t;
    int now_s=0;
    rep(i,n){
        if(!mp_s.count(s[i])){
            mp_s[s[i]]=now_s;
            now_s++;
        }
        fs[i]=mp_s[s[i]];
    }

    int now_t=0;
    rep(i,n){
        if(!mp_t.count(t[i])){
            mp_t[t[i]]=now_t;
            now_t++;
        }

        ft[i]=mp_t[t[i]];
    }
    if(fs==ft){
        cout<<"Yes\n";
    }else{
        cout<<"No\n";
    }
}