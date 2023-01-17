#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<string>
#include<queue>
#include<set>
#include<stack>
#include<bitset>
#include<math.h>
#define rep(i, N)  for(int i=0;i<(N);i++)
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using Node = pair<int, int>;
const ll INF = 1000000000;

int gcd(int a, int b) {
	if (a % b == 0)return b;
	else return gcd(b, a % b);
}
int lcm(int a, int b) {
	return a * b / gcd(a, b);
}
int main() {
	int a;
	cin >> a;
	if (a == 7 || a == 5 || a == 3)cout << "YES" << endl;
	else cout << "NO" << endl;
}