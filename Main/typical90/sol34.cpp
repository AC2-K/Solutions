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
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(auto&aa:a){
        cin>>aa;
    }

    int l=0,r=0;
    int sz=0;
    unordered_map<int,int> mp;
    int ans=0;

    for(int i=0,j=0;j<n;j++){
        mp[a[j]]++;
        for(;i<=j&&mp.size()>k;i++){
            mp[a[i]]--;
            if(mp[a[i]]==0)mp.erase(a[i]);
        }

        if(mp.size()<=k)chmax(ans,j-i+1);
    }
    cout<<ans<<'\n';
}