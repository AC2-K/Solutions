#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using Graph=vector<vector<int>>;
int main() {
    int K;
    cin>>K;
    ll R=7;
    for(int i=1;i<=K;i++){
        R%=K;
        if(R%K==0){
            cout<<i<<endl;
            return 0;
        }
        R=10*R+7;
    }
    cout<<-1<<endl;
    return 0;
}