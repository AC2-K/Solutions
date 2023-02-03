#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n,p,q,r,s;
    cin>>n>>p>>q>>r>>s;
    p--,q--,r--,s--;    //0-indexになおす

    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    vector<int> b(n);   //操作後の数列

    for(int i=0;i<n;i++){
        if(i<p||(q<i&&i<r)||s<i)b[i]=a[i];
        else if(p<=i&&i<=q)b[i]=a[i-p+r];
        else b[i]=a[i-r+p];
    }
    //出力
    for(int i=0;i<n;i++){
        cout<<b[i]<<' ';
    }
    cout<<'\n';
}