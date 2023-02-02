#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int cnt=0;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        if(s=="For"){
            cnt++;
        }
    }
    if(cnt>n/2)cout<<"Yes\n";
    else cout<<"No\n";
}