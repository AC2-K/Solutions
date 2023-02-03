#include<bits/stdc++.h>
using namespace std;
template<class T,class U>void chmax(T&x,U y){x=max(x,y);}
int main(){
    const int inf=1e9;
    using ll=long long;

    //入力受け取り
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto&aa:a){
        cin>>aa;
    }
    vector<string> s(n);
    for(auto&ss:s){
        cin>>ss;
    }
    vector<vector<int>> dist(n,vector<int>(n,inf)); //dist[i][j]:=i->jの最短距離(到達できないときはinf)
    vector<vector<ll>> val_sum(n,vector<ll>(n));  //val_sum[i][j]:=i->jでのお土産の価値の和の最大値(iを除く!!!)
    

    for(int i=0;i<n;i++)for(int j=0;j<n;j++){
        if(s[i][j]=='Y'){
            dist[i][j]=1;
            val_sum[i][j]=a[j];
        }
    }


    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int pre_dist=dist[i][j];    //i->j
                int new_dist=dist[i][k]+dist[k][j];     //i->k->j

                if(pre_dist<new_dist)continue;  //悪化したらダメ

                //処理が違うことに注意!!!
                if(pre_dist==new_dist){
                    chmax(val_sum[i][j],val_sum[i][k]+val_sum[k][j]);
                }else{
                    dist[i][j]=dist[i][k]+dist[k][j];
                    val_sum[i][j]=val_sum[i][k]+val_sum[k][j];
                }
            }
        }
    }


    //クエリに答える

    int q;
    cin>>q;
    while(q--){
        int u,v;
        cin>>u>>v;
        u--;
        v--;

        if(dist[u][v]>=inf){
            cout<<"Impossible\n";
        }else{
            cout<<dist[u][v]<<' '<<a[u]+val_sum[u][v]<<'\n';
        }
    }
}