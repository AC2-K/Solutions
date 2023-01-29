
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
    deque<char> deq;
    rep(i,s.size()){
        deq.push_back(s[i]);
    }
    bool rev=false;

    int q;
    cin>>q;
    while(q--){
        int t;
        cin>>t;
        if(t==1){
            rev=(!rev);
        }else{
            int f;
            char c;
            cin>>f>>c;
            if(rev){
                if(f==1)deq.push_back(c);
                else deq.push_front(c);
            }else{
                if(f==1)deq.push_front(c);
                else deq.push_back(c);
            }
        }
    }
    rep(i,deq.size()){
        int p=i;
        if(rev)p=deq.size()-p-1;
        cout<<deq[p];
    }
    cout<<endl;
}