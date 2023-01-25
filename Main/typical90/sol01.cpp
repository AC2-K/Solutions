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
    int n,l,k;
    cin>>n>>l>>k;
    k++;
    vector<int> a(n+2);
    a[0]=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    a.back()=l;

    //全部をlim以上にできるか?
    auto is_ok=[&](int lim)-> bool {
        int pre=0;
        int now=0;
        rep(i,k){
            while(now<=n+1&&a[now]-a[pre]<lim){
                now++;
            }

            if(a[now]-a[pre]<lim||now>=n+2)return false;
            pre=now;
        }

        return true;
    };

    int ng=l+1;
    int ok=-1;
    while(abs(ng-ok)>1){
        int mid=(ok+ng)/2;
        if(is_ok(mid))ok=mid;
        else ng=mid;
    }

    cout<<ok<<endl;
}