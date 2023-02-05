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
    int n,m;
    cin>>n>>m;
    int x[12],y[12];
    rep(i,n){
        cin>>x[i]>>y[i];
    }

    int p[5],q[5];
    rep(i,m){
        cin>>p[i]>>q[i];
    }
    double dp[1<<12][1<<5][20]; //dp[S][T][p]:=訪れた町がS,訪れた宝箱がT,現在位置(p>=nのとき、宝箱p-n,そうじゃないときは町p)のとなるような最短経路長
    bool flag[1<<12][1<<5][20];
    
    function<double(ll,ll)> dist=[&](ll dx,ll dy)-> double {
        return sqrt(dx*dx+dy*dy);
    };
    rep(s,n+m){
        if(s>=n){
            flag[0][1<<(s-n)][s]=true;
            dp[0][1<<(1<<s-n)][s]=dist(p[s-n],q[s-n]);
        }else{
            flag[1<<s][0][s]=true;
            dp[1<<s][0][s]=dist(x[s],y[s]);
        }
    }
    function<double(int,int,int)> f=[&](int S,int T,int pos)-> double {
        if(flag[S][T][pos]){
            return dp[S][T][pos];
        }
        flag[S][T][pos]=true;
        int cur_x=0;
        int cur_y=0;
        if(pos>=n){
            cur_x=p[pos-n];
            cur_y=q[pos-n];
        }else{
            cur_x=x[pos];
            cur_y=y[pos];
        }

        //Sから来たとき
        double res=inf;
        int booster=popcount(T);
        rep(i,n){
            if(S&(1<<i)){
                int pre_S=S&(~(1<<i));
                double d=dist(x[i]-cur_x,y[i]-cur_y);
                d/=(1<<booster);
                chmin(res,dp[pre_S][T][i]+d);
            }
        }
        booster--;
        rep(i,m){
            int id=i+n;
            if(T&(1<<id)){
                int pre_T=T&(~(1<<i));
                double d=dist(p[i]-cur_x,q[i]-cur_y);
                d/=(1<<booster);
                chmin(res,dp[S][pre_T][id]+d);
            }
        }
        return dp[S][T][pos]=res;
    };
    double ans=infl;
    rep(t,m)rep(T,1<<m){
        chmin(ans,f((1<<n)-1,T,t));
    }
    cout<<ans<<endl;
}