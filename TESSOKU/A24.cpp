#include<bits/stdc++.h>
using namespace std;
//#include<atcoder/all>
//using namespace atcoder;
//#include<iomanip>
//#include<limits>
//cout << fixed << setprecision(10);
#define rep(i, N)  for(int i=0;i<(N);i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;
using ld = long double;
using Graph = vector<vector<int>>;
using P = pair<int, int>;
const int INF = 1e9;
const ll INFL = 1e18;
const ll MOD = 1e9 + 7;
const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };
int main() {
    int n;
    cin>>n;
    vector<int> a(n);
    rep(i,n)cin>>a[i];
    vector<int> l(n+1);
    vector<int> dp(n);
    int len=0;
    rep(i,n){
        dp[i]=1;
        int pos=lower_bound(l.begin()+1,l.begin()+len+1,a[i])-l.begin();
        dp[i]=pos;
        l[dp[i]]=a[i];
        if(dp[i]>len)len++;
    }
    cout<<len<<endl;
}