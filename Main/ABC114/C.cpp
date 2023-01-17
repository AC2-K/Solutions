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
const int INF = 1e9;
const ll INFL = 1e18;
const ld eps = ld(0.000000001);
const long double pi = 3.141592653589793;
const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };
/*
template<class T>using v=vector<T>;
template<class T>using vv=v<v<T>>;
template<class T>using vvv=v<vv<T>>;
template<class T>using vvvv=v<vvv<T>>;
*/
template<class T>void chmax(T&x,T y){if(x<y)x=y;}
template<class T>void chmin(T&x,T y){if(x>y)x=y;}
int main() {
    int n;
    cin>>n;
    auto check=[&](ll num)-> bool {
        if(num>n)return false;
        bool fl1=false,fl2=false,fl3=false;
        auto s=to_string(num);
        for(auto c:s){
            if(c=='3')fl1=true;
            else if(c=='7')fl2=true;
            else if(c=='5')fl3=true;
        }
        return fl1&&fl2&&fl3;
    };
    int ans=0;
    const int vec[]={7,5,3};
    auto dfs=[&](auto f,ll num)-> void {
        if(check(num))ans++;
        rep(i,3){
            num*=10;
            num+=vec[i];
            if(num<=n)f(f,num);
            num/=10;
        }
        return;
    };
    dfs(dfs,0);
    cout<<ans<<endl;
}