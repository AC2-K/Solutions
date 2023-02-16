#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	int n;
	cin >> n;
	if (n == 0) {
		cout << 0 << '\n';
		return 0;
	}
	string res;
	while (n != 1) {
		if (n & 1)res += "1";
		else res += "0";

		if (n < 0) {
			n *= -1;
			n = (n + 1) >> 1;
		}
		else {
			n >>= 1;
			n *= -1;
		}
	}
	res += "1";
	reverse(res.begin(), res.end());
	cout << res << '\n';
}