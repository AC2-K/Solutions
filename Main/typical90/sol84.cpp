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
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<int> sumx(n+1);
    vector<int> sumo(n+1);
    rep(i,n){
        sumx[i+1]=sumx[i]+(s[i]=='x');
        sumo[i+1]=sumo[i]+(s[i]=='o');
    }
    ll ans=0;
    rep(i,n){
        int ok=i;
        int ng=n+1;
        while(abs(ng-ok)>1){
            int mid=(ng+ok)/2;
            if(sumx[mid]-sumx[i]==0||sumo[mid]-sumo[i]==0)ok=mid;
            else ng=mid;
        }
        ans+=n-ok;
    }
    cout<<ans<<endl;
}