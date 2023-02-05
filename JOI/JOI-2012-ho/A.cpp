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
    string s;
    cin>>s;
    vector<pair<char,int>> vec;
    int len=s.size();
    for(int i=0;i<len;){
        int j=i;
        int c=0;
        for(;j<len&&s[i]==s[j];j++){
            c++;
        }
        vec.emplace_back(s[i],c);
        i=j;
    }
    #ifdef ONLINE_JUDGE
    #else
    for(auto v:vec){
        cout<<v.first<<' '<<v.second<<endl;
    }
    #endif
    int sz_vec=vec.size();
    int ans=0;
    for(int i=2;i<sz_vec;i++){
        if(vec[i-2].first=='J'&&vec[i-1].first=='O'&&vec[i].first=='I'){
            if(vec[i-1].second<=vec[i].second&&vec[i-1].second<=vec[i-2].second){
                chmax(ans,vec[i-1].second);
            }
        }
    }
    cout<<ans<<endl;
}