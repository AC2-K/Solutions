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
	vector<int> A(3);
	cin >> A[0] >> A[1] >> A[2];
	sort(A.begin(), A.end());
	cout << A[0] + A[1] + 10 * A[2] << endl;
}