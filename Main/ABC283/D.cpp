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
    string s;
    cin>>s;
    const int alpha='z'-'a'+1;
    vector<stack<int>> rank(alpha);
    int n=s.size();
    int now=0;
    rep(i,n){
        if(s[i]=='(')now++;
        else if(s[i]==')'){
            rep(c,alpha){
                if(rank[c].empty())continue;
                int cnt=0;
                while(rank[c].size()&&rank[c].top()==now)rank[c].pop(),cnt++;
                if(cnt>1){
                    cout<<"No"<<endl;
                    return 0;
                }
            }
            now--;
        }
        else{
            if(rank[s[i]-'a'].size()&&rank[s[i]-'a'].top()<=now){
                cout<<"No"<<endl;
                return 0;
            }
            rank[s[i]-'a'].push(now);
        }
    }
    cout<<"Yes"<<endl;
    return 0;
}