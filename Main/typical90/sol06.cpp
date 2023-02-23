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
    int n,k;
    string s;
    cin>>n>>k>>s;

    vector<vector<int>> c_pos('z'-'a'+1);
    rep(i,n){
        c_pos[s[i]-'a'].emplace_back(i);
    }
    int cur=-1;
    while(k){
        rep(c,'z'-'a'+1){
            auto it=upper_bound(all(c_pos[c]),cur);
            if(it==c_pos[c].end()){
                continue;
            }

            if(n-(*it)>=k){
                cout<<(char)('a'+c);
                cur=*it;
                k--;
                break;
            }
        }
    }
    cout<<'\n';
}