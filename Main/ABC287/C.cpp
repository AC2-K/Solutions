#include<iostream>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
int main(){
	int n,m;
	cin>>n>>m;
	if(m!=n-1){
		cout<<"No\n";
		return 0;
	}
	dsu uf(n);
	vector<int> deg(n);
	for(int i=0;i<m;i++){
		int v,u;
		cin>>v>>u;
		v--;
		u--;
		deg[v]++;
		deg[u]++;
		if(uf.same(v,u)){
			//サイクルがあったとき
			cout<<"No\n";
			return 0;
		}
		uf.merge(v,u);
	}
	if(uf.groups().size()>1){
		//非連結のとき
		cout<<"No\n";
		return 0;
	}
	for(int v=0;v<n;v++){
		//次数が2より大きい頂点があるとき
		if(deg[v]>2){
			cout<<"No\n";
			return 0;
		}
	}
	cout<<"Yes\n";
}