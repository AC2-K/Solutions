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
template<class T>void chmax(T&x,T y){if(x<y)x=y;}
template<class T>void chmin(T&x,T y){if(x>y)x=y;}
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
    ios::sync_with_stdio(false);
    cin.tie(0);
    int h,w;
    cin>>h>>w;
    int q;
    cin>>q;

    DSU dsu(h*w);
    vector<vector<bool>> is_red(h,vector<bool>(w,false));
    auto id=[&](int ii,int jj){return w*ii+jj;};
    while(q--){
        int t;
        cin>>t;
        if(t==1){
            int r,c;
            cin>>r>>c;
            r--;
            c--;
            is_red[r][c]=true;
            rep(ii,4){
                int ni=r+dx[ii];
                int nj=c+dy[ii];
                if(ni<0||nj<0||ni>=h||nj>=w)continue;
                if(is_red[ni][nj])dsu.merge(id(r,c),id(ni,nj));
            }
        }else{
            int ra,ca,rb,cb;
            cin>>ra>>ca>>rb>>cb;
            ra--;ca--;rb--;cb--;

            if(!is_red[ra][ca]||!is_red[rb][cb]){
                cout<<"No\n";
            }
            else if(dsu.same(id(ra,ca),id(rb,cb))){
                cout<<"Yes\n";
            }else{
                cout<<"No\n";
            }
        }
    }
}