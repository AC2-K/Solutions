#include<bits/stdc++.h>
using namespace std;
#define chmin(x,y) if(x>=y){x=y;}
int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    vector<pair<int,int>> p(n+m);
    for(auto&[x,y]:p){
        scanf("%d%d",&x,&y);
    }
    vector<vector<double>> dp(1<<(n+m),vector<double>(n+m,1e18));
    for(int i=0;i<n+m;i++){
        dp[1<<i][i]=hypot(p[i].first,p[i].second);
    }

    for(int S=1;S<(1<<(n+m));S++)for(int i=0;i<n+m;i++)if((S>>i)&1){
        double boost=pow(0.5,__builtin_popcount(S>>n));
        for(int ni=0;ni<n+m;ni++){
            if((S>>ni)&1)continue;
            int dx=p[i].first-p[ni].first;
            int dy=p[i].second-p[ni].second;
            double dist=hypot(dx,dy)*boost;
            chmin(dp[S|(1<<ni)][ni],dp[S][i]+dist);
        }
    }
    double mn=1e18;
    for(int i=0;i<n+m;i++)for(int s=(1<<n)-1;s<1<<(n+m);s+=1<<n){
        chmin(mn,dp[s][i]+hypot(p[i].first,p[i].second)*pow(0.5,__builtin_popcount(s>>n)));
    }
    cout<<fixed<<setprecision(12)<<mn<<'\n';
}