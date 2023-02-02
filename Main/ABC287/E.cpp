#include<bits/stdc++.h>

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
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
        return (c - 'a' + 1);
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
    /*
    int lcp(const vector<ll>&a,const vector<ll>&b){
        int ng=min(a.size(),b.size())+1;
        int ok=0;
        while(abs(ng-ok)>1){
            int mid=(ng+ok)/2;

            if(a[mid]==b[mid])ok=mid;
            else ng=mid;
        }

        return ok;
    }
    */
};

class RollingHash2 {
    
    static const ll mod = MOD2;
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
    RollingHash2(ll base = generate_base()) :base(generate_base()), powers{ 1 } {	} 
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

    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<string> ss(n);
    RollingHash rh;
    RollingHash2 rh2;

    vector<vector<ll>> hash(n);
    vector<vector<ll>> hash2(n);
    rep(i,n){
        string s;
        cin>>s;
        ss[i]=s;
        hash[i]=rh.build(s);
        hash2[i]=rh2.build(s);
    }
    //const int LEN_MAX=1e5;
    map<ll,map<ll,ll>> prefixes;  //先頭i文字を並べまくったやつ
    map<ll,map<ll,ll>> prefixes2;
    for(auto&h:hash){
        rep(len,h.size()){
            prefixes[len][h[len]]++;
        }
    }
    for(auto&h:hash2){
        rep(len,h.size()){
            prefixes2[len][h[len]]++;
        }
    }

    rep(i,n){
        int ng=hash[i].size()+1;
        int ok=0;
        while(abs(ok-ng)>1){
            int mid=(ok+ng)/2;
            if(prefixes[mid][hash[i][mid]]>=2&&prefixes2[mid][hash2[i][mid]]>=2){
                ok=mid;
            }else{
                ng=mid;
            }
        }
        cout<<ok<<endl;
    }
}