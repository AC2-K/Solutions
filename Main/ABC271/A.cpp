#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<string>
#define rep(i,N)for(int i=0;i<(int)N;i++) 
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
const ll INF = 1000000000;
char Func(int n) {
	if (n <= 9)return '0' + n;
	else return 'A' + n - 10;
}
int main() {
	int N;
	cin >> N;
	char A = Func(N % 16);
	char B = Func(N / 16);
	cout << B << A << endl;
}