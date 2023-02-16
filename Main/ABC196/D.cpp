#include<bits/stdc++.h>
using namespace std;
int dp[17][27][1 << 16];
bool flag[17][17][1 << 16];
constexpr int dx[] = { 1,0 };
constexpr int dy[] = { 0,1 };
int main() {
	int h, w, A, B;
	cin >> h >> w >> A >> B;
	
	function<int(int,int,int)> f = [&](int a, int b,int S)-> int {
		if (flag[a][b][S]) {
			return dp[a][b][S];
		}
		flag[a][b][S] = true;
		int res = 0;
		int x = -1;
		for (int i = 0; i < h * w; i++) {
			if(!(S&(1<<i))){
				x = i;
				break;
			}
		}
		if (x == -1) {
			return dp[a][b][S] = 1;
		}
		if (b) {
			res += f(a, b - 1, S | (1 << x));
		}

		if (a) {
			int vi = x / w;
			int vj = x % w;
			for (int k = 0; k < 2; k++) {
				int ni = vi + dx[k];
				int nj = vj + dy[k];

				if (ni < 0 || nj < 0 || ni >= h || nj >= w)continue;

				int idx = w * ni + nj;

				if (S & (1 << idx))continue;

				res += f(a - 1, b, S | (1 << x) | (1 << idx));
			}
		}

		return dp[a][b][S] = res;
	};

	cout << f(A, B, 0) << '\n';
}