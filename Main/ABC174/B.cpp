#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  long long D;
  cin>>N>>D;
  vector<long long> X(N),Y(N);
  for(int i=0;i<N;i++)cin>>X[i]>>Y[i];
  
  int cnt=0;
  for(int i=0;i<N;i++){
    if(X[i]*X[i]+Y[i]*Y[i]<=D*D)cnt++;
  }
  cout<<cnt<<endl;
}