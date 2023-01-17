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
vector<bool> prime_checker(int N) {
    vector<bool> primes(N + 1, true);

    primes[0] = false;
    primes[1] = false;

    // ふるい
    for (int p = 2; p <= N; ++p) {
        if (!primes[p]) continue;
        for (int i = 2; p * i <= N; i++) {
            primes[p * i] = false;
        }
    }

    return primes;
}
const int NUM_MAX=1e7;
int main() {
    auto res=prime_checker(NUM_MAX);

    vector<int> fact_cnt(NUM_MAX+1);
    for(int p=2;p<=NUM_MAX;p++){
        if(!res[p])continue;
        for(int num=p;num<=NUM_MAX;num+=p){
            fact_cnt[num]++;
        }
    }
    

    int n,k;
    cin>>n>>k;
    int ans=0;
    for(int p=2;p<=n;p++){
        if(fact_cnt[p]>=k){
            ans++;
        }
    }
    cout<<ans<<endl;
}