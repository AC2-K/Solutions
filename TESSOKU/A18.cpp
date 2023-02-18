#include<iostream>
#include<bitset>
using namespace std;
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
constexpr int s_max=10000;
bitset<s_max+1> dp(1);
int n,s,ai;
int main(){
    scanf("%d%d",&n,&s);
    for(int i=0;i<n;i++){
        scanf("%d",&ai);
        dp|=dp<<ai;
    }
    if(dp.test(s)){
        puts("Yes\n");
    }else{
        puts("No\n");
    }
}