#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
int main() {
	int n, x;
	cin >> n >> x;
	vector<int> xi(n);
	for (auto& xx : xi) {
		cin >> xx;
	}
	xi.emplace_back(x);
	sort(xi.begin(), xi.end());
	vector<int> d(n);
	for (int i = 0; i < n; i++) {
		d[i] = xi[i + 1] - xi[i];
	}

	int g = 0;
	for (auto& dd : d) {
		g = gcd(dd, g);
	}
	cout << g << '\n';
}