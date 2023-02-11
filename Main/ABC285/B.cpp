#include<iostream>
using namespace std;
int main(){
    int n;
    string s;
    cin>>n>>s;
    
    for(int i=1;i<n;i++){
        int ans=0;
        for(int j=1;j<=n;j++){
            if(i+j>n){
                ans=j-1;
                break;
            }
            if(s[j-1]==s[j+i-1]){
                ans=j-1;
                break;
            }
        }
        cout<<ans<<'\n';
    }
}