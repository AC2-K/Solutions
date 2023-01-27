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
int main() {
    //Mo's algorithm
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,q;
    scanf("%d%d",&n,&q);
    vector<int> a(n);
    for(auto&aa:a){
        scanf("%d",&aa);
        aa--;
    }


    int sqrt_q=sqrt(q);

    vector<int> l(q),r(q);
    rep(i,q){
        scanf("%d%d",&l[i],&r[i]);
        l[i]--;
    }

    vector<int> idx(q);
    rep(i,q)idx[i]=i;
    sort(all(idx),[&](int i,int j){
        int pi=l[i]/sqrt_q,pj=l[j]/sqrt_q;
        if(pi!=pj)return l[i]<l[j];
        if(pi&1)return r[i]>r[j];
        return r[i]<r[j]; 
    });

    vector<int> cnt(n+1,0);
	int sz=0;
    int now_l=0,now_r=0;
    vector<int> ans(q);
    auto add=[&](int pos){
		if(cnt[a[pos]]==0)sz++;
        cnt[a[pos]]++;
    };
    auto del=[&](int pos){
        cnt[a[pos]]--;
        if(cnt[a[pos]]==0)sz--;
    };

    rep(i,q){
        while(now_l > l[idx[i]]) add(--now_l);
        while(now_r < r[idx[i]]) add(now_r++);
        while(now_l < l[idx[i]]) del(now_l++);
        while(now_r > r[idx[i]]) del(--now_r);

        ans[idx[i]]=sz;
    }
    rep(i,q){
        cout<<ans[i]<<'\n';
    }
}