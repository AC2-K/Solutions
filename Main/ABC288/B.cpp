#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	int n,k;
	cin>>n>>k;
	vector<string> s(n);
	for(int i=0;i<n;i++){
		cin>>s[i];
	}

	vector<string> vec(k);	//上位k人を抽出する
	for(int i=0;i<k;i++){
		vec[i]=s[i];
	}

	sort(vec.begin(),vec.end());	//辞書順で並べ替える
	//出力
	for(int i=0;i<k;i++){
		cout<<vec[i]<<'\n';
	}
}