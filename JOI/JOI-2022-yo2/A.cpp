#include <bits/stdc++.h>
using namespace std;
int main(){
  int Q;
  cin>>Q;
  stack<string> book;
  for(int i=0;i<Q;i++){
    string S;
    cin>>S;
    if(S=="READ"){
      cout<<book.top()<<endl;
      book.pop();
    }
    else{
      book.push(S);
    }
  }
}