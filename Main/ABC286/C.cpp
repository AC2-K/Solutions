#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,a,b;
    string s;
    cin>>n>>a>>b>>s;

    const long long infl=1e18;
    long long ans=infl;
    for(int i=0;i<=n;i++){
        int c=0;
        for(int j=0;j<n;j++){
            if(s[j]!=s[n-j-1]){
                c++;
            }
        }

        c/=2;
        ans=min(ans,1ll*a*i+1ll*c*b);
        s=s.substr(1)+s.front();
    }
    cout<<ans<<'\n';
}