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
    int n,c;
    cin>>n>>c;
    /*
    vector<int> t(n),a(n);
    rep(i,n){
        cin>>t[i]>>a[i];
    }
    vector<vector<bool>> ans(n,vector<bool>(32));
    rep(p,31){
        int msk=(1ll<<p);
        vector<vector<bool>> res(2,vector<bool>(n+1));
        res[0][0]=false,res[1][0]=true;
        rep(bit,2)rep(i,n){
            if(t[i]==1){
                res[bit][i+1]=res[bit][i]&(a[i]&(1<<p));   
            }else if(t[i]==2){
                res[bit][i+1]=res[bit][i]|(a[i]&(1<<p));
            }else{
                res[bit][i+1]=res[bit][i]^(a[i]&(1<<p));
            }
        }

        rep(i,n){
            res[i+1][p]=res[res[i][p]
        }
    }
    */

    vector<int> t(n);
    vector<bitset<30>> a(n);
    rep(i,n){
        int ai;
        cin>>t[i]>>ai;
        a[i]=ai;
    }

    bitset<30> one((1<<30)-1),zero(0);
    bitset<30> res[n+1][2];
    res[0][0]=zero,res[0][1]=one;
    rep(i,n)rep(j,2){
        if(t[i]==1){
            res[i+1][j]=res[i][j]&a[i];
        }else if(t[i]==2){
            res[i+1][j]=res[i][j]|a[i];
        }else{
            res[i+1][j]=res[i][j]^a[i];
        }
    }
    bitset<30> x(c);
    rep(i,n){
        int ans=0;
        rep(j,30){
            x[j]=res[i+1][x[j]][j];

            ans+=(1<<j)*x[j];
        }
        cout<<ans<<'\n';
    }
}