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
    int n;
    cin>>n;
    vector<string> ans;
    rep(msk,1<<n){
        string s;
        rep(i,n){
            if((msk>>i)&1){
                s+=')';
            }else{
                s+='(';
            }
        }

        stack<char> st;
        bool is_ok=true;
        rep(i,n){
            if(s[i]=='('){
                st.emplace('(');
            }else{
                if(st.empty()){
                    is_ok=false;
                }
                else{
                    st.pop();
                }
            }
        }
        if(is_ok&&st.empty()){
            ans.emplace_back(s);
        }
    }
    sort(all(ans));
    for(const auto&s:ans){
        cout<<s<<'\n';
    }
}