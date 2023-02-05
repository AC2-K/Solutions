n,m=map(int,input().split())
a=list(map(int,input().split()))

inf=1e9
dp=[-inf]*(n+1)
dp[0]=0

num=[0,2,5,5,4,5,6,3,7,6]
for i in range(n):
    for j in a:
        if i+num[j]<=n:
            dp[i+num[j]]=max(dp[i+num[j]],10*dp[i]+j)

print(dp[n])