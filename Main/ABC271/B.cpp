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
	int N,Q;
	cin >> N >> Q;
	vector<int> L(N);
	vector<vector<int>> A(N + 1);
	for (int i = 0;i < N;i++) {
		cin >> L[i];
		for (int j = 0;j < L[i];j++) {
			int a;
			cin >> a;
			A[i].push_back(a);
		}
	}
	for (int i = 0;i < Q;i++) {
		int S, T;
		cin >> S >> T;
		S--;
		T--;
		cout << A[S][T] << endl;
	}
}