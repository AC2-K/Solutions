#include<bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
int main(){
    int n,x;
    scanf("%d%d",&n,&x);
    constexpr int max_x=1e4+1;
    bitset<max_x> dp;
    dp.set(0);
    for(int i=0;i<n;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        for(int k=0;k<b;k++){
            dp|=dp<<a;
        }

        if(dp.test(x)){
            printf("Yes\n");
            return 0;
        }
    }
    printf("No\n");
    return 0;
}