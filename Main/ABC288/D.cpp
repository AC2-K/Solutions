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
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(auto&aa:a){
        cin>>aa;
    }

    vector<vector<ll>> sum(k,vector<ll>(n+1));
    rep(i,n){
        rep(j,k){
            sum[j][i+1]=sum[j][i];
        }
        sum[i%k][i+1]+=a[i];
    }


    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        l--,r--;
        ll s=sum[0][r+1]-sum[0][l];
        bool fl=true;
        rep(i,k){
            if(sum[i][r+1]-sum[i][l]!=s){
                fl=false;
            }
        }
        if(fl){
            cout<<"Yes\n";
        }else{
            cout<<"No\n";
        }
    }
}