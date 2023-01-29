
#include<bits/stdc++.h>

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
int n;
char front[16],back[16];
bool dp[1<<16][16],flag[1<<16][16];
//f(S,i)=dp[S][i]:=すでに言った集合がSで、次をiを言うとき勝てるか?
bool f(int S,int i){
    if(flag[S][i])return dp[S][i];

    flag[S][i]=true;
    for(int nex=0;nex<n;nex++){
        if(S&(1<<nex))continue;
        if(front[nex]!=back[i])continue;

        if(f(S|(1<<nex),nex))return dp[S][i]=false;
    }
    return dp[S][i]=true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        front[i]=s.front();
        back[i]=s.back();
    }
    assert(n<=16);
    for(int i=0;i<n;i++){
        if(f(1<<i,i)){
            cout<<"First\n";
            return 0;
        }
    }
    cout<<"Second\n";
}