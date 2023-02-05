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
    int n;
    cin>>n;
    unordered_map<int,int> cnt;
    int del=0;
    rep(i,n){
        int a;
        cin>>a;
        if(a>n){
            del++;
            continue;
        }
        cnt[a]++;
    }
    auto is_ok=[&](int lim)-> bool { 
        int sold=del;
        for(auto&el:cnt){
            if(el.first>lim)sold+=el.second;
            else if(el.second>=2)sold+=el.second-1;
        }

        int need=0;
        for(int i=1;i<=lim;i++){
            if(cnt[i]==0){
                need++;
            }
        }
        if(need-(sold>>1)<=0){
            return true;
        }else{
            return false;
        }
    };
    int ng=n+1;
    int ok=0;
    while(abs(ok-ng)>1){
        int md=(ok+ng)>>1;
        if(is_ok(md))ok=md;
        else ng=md;
    }
    cout<<ok<<endl;
}