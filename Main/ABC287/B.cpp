#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<string> s(n),t(m);
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    for(int i=0;i<m;i++){
        cin>>t[i];
    }

    int ans=0;
    for(int i=0;i<n;i++){
        bool exist=false;
        
        string sub=s[i].substr(s[i].size()-3);  //末尾3文字
        for(int j=0;j<m;j++){
            if(sub==t[j]){
                exist=true;
            }
        }
        if(exist){
            ans++;
        }
    }
    cout<<ans<<endl;
}