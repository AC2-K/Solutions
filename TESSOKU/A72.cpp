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
    //H,W,Kともにめちゃくちゃ小さい。Kに関しては10程度.
    //Hの方を全探索して、Wに関して調べる。

    int h,w,k;
    cin>>h>>w>>k;
    vector<string> g(h);
    for(auto&el:g)cin>>el;
    vector<ll> bits(w);
    rep(j,w){
        ll pow=1;
        rep(i,h){
            if(g[i][j]=='#'){
                bits[j]+=pow;
            }

            pow<<=1;
        }
    }
    int ans=0;
    rep(tmp,1ll<<h){
        int cnt=popcount(tmp);
        if(cnt>k)continue;
        auto copy_bits=bits;

        for(auto&el:copy_bits){
            el|=tmp;    //塗っちゃう
        }

        sort(all(copy_bits),[](ll a,ll b){return popcount(a)<popcount(b);});    //黒で塗られてる部分が少ない順に見る

        rep(i,k-cnt){
            copy_bits[i]|=(1ll<<h)-1;   //全部立てる
        }


        int res=0;
        for(auto&el:copy_bits){
            res+=popcount(el);
        }
        chmax(ans,res);
    }
    cout<<ans<<endl;
}