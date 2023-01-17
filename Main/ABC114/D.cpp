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
vector<pair<ll, ll>> fact(ll n) {
    vector<pair<ll, ll>> ret;
    for (ll div = 2; div * div <= n; div++) {
        if (n % div != 0)continue;
        ll exp = 0;
        while (n % div == 0) {
            exp++;
            n /= div;
        }
        ret.push_back(make_pair(div, exp));
    }
    if (n != 1)ret.push_back(make_pair(n, 1));
    return ret;
}
int main() {
    vector<int> res;
    int n;
    cin>>n;
    for(int i=2;i<=n;i++){
        auto tmp=fact(i);

        for(auto el:tmp){
            rep(_,el.second){
                res.push_back(el.first);
            }
        }
    }
    sort(all(res));
    vector<int> e;
    for(int i=0;i<res.size();){
        int j=i;
        int cnt=0;
        for(;j<res.size()&&res[i]==res[j];j++){cnt++;}
        e.push_back(cnt);
        i=j;
    }
    int ans=0;
   
    auto dfs=[&](auto f,int pos,ll now_product)-> void {
        if(pos==e.size()){
            if(now_product==75)ans++;

            return;
        }
        int max_exp=e[pos];
        for(int i=0;i<=max_exp;i++){
            now_product*=(i+1);
            if(now_product<=75){
                f(f,pos+1,now_product);
            }
            now_product/=(i+1);
        }
    };
    dfs(dfs,0,1);
    cout<<ans<<endl;
}