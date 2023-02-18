#include<iostream>
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
int n,ai;
long long ans=0;
int b[100];
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&ai);
        b[ai%100]++;
    }
    for(int i=0;i<50;i++){
        int j=100-i;
        if(j==100)j=0;
        if(i==j){
            ans+=b[i]*(b[i]-1);
        }else{
            ans+=b[i]*b[j];
        }
    }
    printf("%lld\n",ans);
}