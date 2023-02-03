#include<bits/stdc++.h>
using namespace std;
//cout << fixed << setprecision(10);
#define rep(i, N)  for(int i=0;i<(N);i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;
using ld = long double;
using Graph = vector<vector<int>>;
using P = pair<int, int>;
const int INF = 1e9;
const ll INFL = 1e18;
const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };
int main() {
	int H,W;
	cin>>H>>W;
	vector<string> S(H);
	rep(i,H)cin>>S[i];
	auto bfs=[&](int sx,int sy){
		if(sx==H-1&&sy==W-1)return INF;

		vector<vector<int>> dist(H,vector<int>(W,-1));
		dist[sx][sy]=0;
		queue<P> que;
		que.emplace(sx,sy);
		while(!que.empty()){
			int vi=que.front().first;
			int vj=que.front().second;
			que.pop();
			rep(i,4){
				int ni=vi+dx[i];
				int nj=vj+dy[i];
				if(ni<0||nj<0||H<=ni||W<=nj)continue;
				if(dist[ni][nj]!=-1)continue;
				if(S[vi][vj]==S[ni][nj])continue;
				dist[ni][nj]=dist[vi][vj]+1;
				que.emplace(ni,nj);
			}
		}
		return dist[H-1][W-1];
	};
	cout<<bfs(0,0)<<endl;
}