#include<bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    const int mod=1e9+7;
    int n;
    string s;
    cin>>n>>s;
    const string str="atcoder";
    int sz=str.size();
    vector<int> dp(vector<int>(sz+1));
    dp[0]=1;
    for(int i=0;i<n;i++)for(int j=0;j<sz;j++){
        if(s[i]==str[j]){
            dp[j+1]+=dp[j];
            dp[j+1]%=mod;
        }
    }
    cout<<dp.back()<<'\n';
}