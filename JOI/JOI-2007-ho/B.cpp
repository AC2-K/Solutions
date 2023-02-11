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
class DSU {
private:
    vector<int> par, rank, siz;
    int N;
public:
    DSU(int n) : par(n, -1), rank(n, 0), siz(n, 1), N(n) {}

    int root(int x) {
        if (par[x] == -1)
            return x;
        else
            return par[x] = root(par[x]);
    }
    bool same(int x, int y) {
        return root(x) == root(y);
    }

    bool merge(int x, int y) {
        int rx = root(x), ry = root(y);
        if (rx == ry)
            return false;

        if (rank[rx] < rank[ry])
            swap(rx, ry);
        par[ry] = rx;

        siz[rx] += siz[ry];
        return true;
    }

    int size(int x) {
        return siz[root(x)];
    }
    int connect() {
        int cnt = 0;
        for (int i = 0; i < N; i++)
            if (root(i) == i)
                cnt++;
        return cnt;
    }
};

int main() {
    int n,k;
    cin>>n>>k;
    vector<int> a(k);
    for(auto&aa:a){
        cin>>aa;
    }
    vector<int> backet(n+1);
    for(auto&aa:a){
        backet[aa]++;
    }
    vector<int> len,back,front;
    for(int i=1;i<=n;){
        if(backet[i]==0){
            i++;
            continue;
        }
        int j=i;
        int c=0;
        while(j<=n&&backet[j]==1){
            j++;
            c++;
        }
        len.emplace_back(c);
        front.emplace_back(i);
        back.emplace_back(j-1);
        i=j;
    }
    /*
    sort(all(a));
    for(auto&aa:a)cout<<aa<<' ';
    cout<<endl;
    */
    if(backet[0]==0){
        cout<<*max_element(all(len))<<endl;
        return 0;
    }
    int sz=len.size();
    /*
    rep(i,sz){
        cout<<front[i]<<' '<<back[i]<<' '<<len[i]<<'\n';
    }
    */
   int ans=0;
    rep(i,sz){
        int k=back[i]+1;
        if(k<=n){
            int l=len[i]+1;
            if(i+1<sz&&front[i+1]==k+1){
                l+=len[i+1];
            }
            chmax(ans,l);
        }
        k=front[i]-1;
        if(k>0){
            int l=len[i]+1;
            if(i-1>=0&&back[i-1]==k-1){
                l+=len[i-1];
            }
            chmax(ans,l);
        }
    }
    cout<<ans<<endl;
}