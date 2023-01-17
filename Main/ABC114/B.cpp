#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<string>
#include<set>
#include<bitset>
#define rep(i, N)  for(int i=0;i<(N);i++)
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<int, int>;
const int INF = 1e9;
const ll LINF = 1e18;


int main() {
	string S;
	cin >> S;
	int N = S.size();
	int ans = INF;
	for (int i = 0;i < N - 3 + 1;i++) {
		string T = S.substr(i, 3);
		int n = stoi(T);
		ans = min(ans, abs(n - 753));
	}
	cout << ans << endl;
}
