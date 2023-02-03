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
#define debug(x) cout<<#x<<" = "<<x<<'\n'
class RollingHash {
    
    static const ll mod = 1e9 + 7;
    const ll base;
    vector<ll> powers;	//base^i
    static inline ll generate_base() {
        mt19937_64 engine(chrono::steady_clock::now().time_since_epoch().count());
        uniform_int_distribution<ll> rand((ll)1, (ll)mod - 1);
        return rand(engine);
    }
    //idの振り方
    ll mapping(char c) {
        return (c - 'a');
    }
    void expand(int siz) {
        if (powers.size() < siz + 1) {
            int pre_siz = powers.size();
            powers.resize(siz + 1);
            for (int i = pre_siz; i <= siz; i++) {
                powers[i] = (powers[i - 1] * base) % mod;
            }
        }
    }

public:
    RollingHash(ll base = generate_base()) :base(generate_base()), powers{ 1 } {	} 
    vector<ll> build(string& s) {
        vector<ll> hash(s.size() + 1);
        for (int i = 1; i <= s.size(); i++) {
            hash[i] = (hash[i-1] * base % mod + mapping(s[i-1])) % mod;
        }
        return hash;
    }

    ll range(vector<ll>&hash,int l, int r) {
        expand(r - l);
        return ((hash[r] + mod - hash[l] * powers[r - l]) % mod + mod) % mod;
    }
};
int main() {
    string s;
    int n;
    int siz_s=s.size();
    cin>>n>>siz_s>>s;
    RollingHash rh;
    string p;
    rep(i,n)p+="IO";
    p+="I";
    auto pn=rh.build(p);
    auto S=rh.build(s);
    /*
    debug(s);
    debug(p);
    debug(n);
    */
    int cnt=0;
    int siz_p=p.size();
    for(int i=0;i+siz_p<=siz_s;i++){
        if(rh.range(S,i,i+siz_p)==rh.range(pn,0,siz_p)){
            cnt++;
        }
    }
    cout<<cnt<<endl;
}