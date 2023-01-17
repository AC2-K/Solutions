#include<bits/stdc++.h>
using namespace std;
using ll=long long;
namespace modulo{
	long long mod;
	void set_mod(ll mod_) {
		mod = mod_;
	}
	class modint {
	private:
		using mint = modint;
		ll value = 0;
	public:
		modint(ll v = mod) {
			v %= mod;
			v = (v + mod) % mod;
			value = v;
		}
		long long val() {
			return value%mod;
		}
		mint operator+(mint fp) {
			return mint(value + fp.val());
		}
		mint operator-(mint fp) {
			return mint(value - fp.val());
		}
		mint operator*(mint fp) {
			return mint(value * fp.val());
		}
		void operator=(mint v) {
			value = v.val();
		}
		void operator=(ll v) {
			if (v < 0)v %= mod, v += mod;
			if (v >= mod)v %= mod;
			value = v;
		}
		void operator+=(mint fp) {
			value = ((value + fp.val() + mod) % mod + mod) % mod;
		}
		void operator-=(mint fp) {
			value = value - fp.val();
			value %= mod;
			value += mod;
			value %= mod;
		}
		void operator*=(mint fp) {
			value = value * fp.val();
			value = (value % mod + mod) % mod;
		}
		bool operator==(mint fp) {
			return value == fp.val();
		}
		bool operator<(mint fp) {
			return value < fp.val();
		}
		bool operator>(mint fp) {
			return value > fp.val();
		}
		bool operator<=(mint fp) {
			return value <= fp.val();
		}
		bool operator>=(mint fp) {
			return value >= fp.val();
		}
		ll inv() {
			long long b = mod, u = 1, v = 0;
			while (b) {
				long long t = value / b;
				value -= t * b; swap(value, b);
				u -= t * v; swap(u, v);
			}
			u %= mod;
			if (u < 0) u += mod;
			return u;
		}
		ll mod_pow(ll exp) {
			ll base = value;
			ll ans = 1;
			base %= mod;
			while (exp > 0) {
				if (exp & 1) {
					ans *= base;
					ans %= mod;
				}
				base *= base;
				base %= mod;
				exp >>= 1;
			}
			return ans;
		}
		ll operator/(mint v) {
			return v.inv() * value % mod;
		}
		void operator/=(mint v) {
			value = value * v.inv() % mod;
		}
	friend istream& operator>>(istream& is, mint& mt) {
		ll v;
		is >> v;
		mt = mint(v);
		return is;
	}
	friend ostream& operator << (ostream& os, mint& mt) {
		return os << mt.val();
	}
	};
};

int main(){
	mt19937 mt;
	int Q=1e7;
	while(Q--){
		ll v=mt();
		ll mod=mt();
		v%=mod;
		if(mod<=0)continue;
		if(__gcd(v,mod)!=1)continue;
		modulo::set_mod(mod);
		ll u=modulo::modint(v).inv();
		if(u*v%mod!=1){
			cout<<v<<' '<<u<<' '<<mod<<'\n';
			return 0;
		}
	}
}