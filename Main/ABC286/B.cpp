#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    string s;
    cin>>n>>s;
    string t;
    int pos=0;  //iのこと
    while(pos<n){
        if(s.substr(pos,2)=="na"){
            t+="nya";
            pos+=2;
        }else{
            t+=s[pos];
            pos+=1;
        }
    }
    cout<<t<<'\n';
}