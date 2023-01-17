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
    for(auto&aa:a)cin>>aa;
    //全部がK以下になるようにする。
    //丸太iをx以下に分割するためには、ceil(A_i/x)-1回やる必要がある。


    auto f=[&](int lim)-> bool {
        int cnt=0;
        for(auto aa:a){
            cnt+=(aa+lim-1)/lim-1;
        }
        if(cnt<=k)return true;
        else return false;
    };

    int ng=0;
    int ok=inf;


    while(abs(ng-ok)>1){
        int mid=(ok+ng)/2;

        if(f(mid))ok=mid;
        else ng=mid;
    }

    cout<<ok<<endl;
}