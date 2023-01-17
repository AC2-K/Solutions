#include<iostream>
#include<algorithm>
#include<vector>
#include<random>
#include<chrono>
using namespace std;
using ll = long long;
class RollingHash {
	static const ll mod = 1e9 + 7;
	const ll base;
	vector<ll> pow;
	static inline ll generate_base() {
		mt19937_64 engine(chrono::steady_clock::now().time_since_epoch().count());
		uniform_int_distribution<ll> rand((ll)1, (ll)mod - 1);
		return rand(engine);
	}
	//id
	ll id(char c) {
		return (c - 'a' + 1);
	}
	void expand(int siz) {
		if ((int)pow.size() >= siz)return;

		int pre_siz = pow.size();
		pow.resize(siz + 1);
		for (int i = pre_siz; i <= siz; i++) {
			pow[i] = (pow[i - 1] * base) % mod;
		}
	}

public:
	RollingHash(ll base_ = generate_base()) :base(base_), pow{ 1 } {	}
	vector<ll> build(string& s) {
		vector<ll> hash(s.size() + 1);
		for (int i = 0; i < (int)s.size(); i++) {
			hash[i + 1] = (hash[i] * base % mod + id(s[i])) % mod;
		}
		return hash;
	}
	ll range(vector<ll>& hash, int l, int r) {
		expand(r - l);
		return ((hash[r] + mod - hash[l] * pow[r - l]) % mod + mod) % mod;
	}
};

int main() {
	int n;
	cin >> n;
	string T;
	cin >> T;
	string A = T.substr(0, n);
	string B = T.substr(n, n);
	reverse(B.begin(), B.end());
	RollingHash rh;
	auto a = rh.build(A);
	auto b = rh.build(B);
	for (int i = 0; i <= n; i++) {
		if (rh.range(a, 0, i) != rh.range(b, n - i, n))continue;
		if (rh.range(a, i, n) != rh.range(b, 0, n - i))continue;
		cout << A.substr(0, i) << T.substr(n + i) << endl;
		cout << i << endl;
		return 0;
	}
	cout << -1 << endl;
	return 0;
}
