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
    int n,q;
    cin>>n>>q;
    vector<int> a(n);
    for(auto&aa:a)cin>>aa;

    int shift=0;
    while(q--){
        int t;
        cin>>t;
        if(t==1){
            int x,y;
            cin>>x>>y;
            x--,y--;
            x=((x-shift)%n+n)%n;
            y=((y-shift)%n+n)%n;

            swap(a[x],a[y]);
        }else if(t==2){
            int x,y;
            cin>>x>>y;
            shift++;
        }else{
            int x,y;
            cin>>x>>y;
            x--;
            x=((x-shift)%n+n)%n;
            cout<<a[x]<<'\n';
        }
    }
}