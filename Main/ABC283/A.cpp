#include<bits/stdc++.h>
using namespace std;
//cout << fixed << setprecision(10);
#define rep(i, N)  for(int i=0;i<(N);i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;
using graph = vector<vector<int>>;
int main() {
    int a,b;
    cin>>a>>b;
    ll pow=1;
    rep(i,b){
        pow*=a;
    }
    cout<<pow<<endl;
}