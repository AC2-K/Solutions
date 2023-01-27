
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
    scanf("%d",&n);
    vector<int> a(n);
    for(auto&aa:a){
        scanf("%d",&aa);
        aa--;
    }

    vector<int> cnt(n);
    int ans=0;

    int q;
    cin>>q;
    vector<int> idx(q),l(q),r(q);
    iota(all(idx),0);
    rep(i,q){
        scanf("%d%d",&l[i],&r[i]);
        l[i]--;
    }

    auto del=[&](int x){
        cnt[a[x]]--;
        if(cnt[a[x]]%2==1)ans--;
    };

    auto add=[&](int x){
        cnt[a[x]]++;
        if(cnt[a[x]]%2==0)ans++;
    };

    int sqrt_q=sqrt(q);
    sort(all(idx),[&](int i,int j){
        int p_i=l[i]/sqrt_q,p_j=l[j]/sqrt_q;
        if(p_i!=p_j)return p_i<p_j;
        if(p_i%2==0)return r[i]<r[j];
        else return r[j]<r[i];
    });

    int now_r=0,now_l=0;
    vector<int> answers(q);
    rep(i,q){
        while(now_l>l[idx[i]])add(--now_l);
        while(now_r<r[idx[i]])add(now_r++);
        while(now_l<l[idx[i]])del(now_l++);
        while(now_r>r[idx[i]])del(--now_r);

        answers[idx[i]]=ans;
    }

    for(auto&aa:answers){
        printf("%d\n",aa);
    }
}