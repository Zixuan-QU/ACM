#include<limits.h>
#include<iterator>
#include<stdlib.h>
#include<stdio.h>
#include<vector>
#include<iterator>
#include<algorithm>
#include<iostream>
#include<iomanip>
#include<unordered_map>

using namespace std;

int n,cap;

int weight[100005],steps[100005],dist[100005],res[100005];

int main(){
	freopen("input","r+",stdin);
	int ncase;
	cin>>ncase;
	while(ncase--){
		cin>>cap>>n;
		weight[0]=0;
		dist[0] = 0;
		steps[0]=0;
		res[0]=0;
		int x,y,w,prex=0,prey=0;
		for(int i=1;i<=n;i++){
			cin>>x>>y>>w;
			dist[i] = x+y;
			steps[i] = steps[i-1]+abs(x-prex)+abs(y-prey);
			weight[i] = weight[i-1]+w;
			res[i] = INT_MAX;
			for(int j=i;j>=1;j--){
				if(weight[i]-weight[j-1]>cap) break;
				res[i] = min(res[i],res[j-1]+steps[i]-steps[j]+dist[i]+dist[j]);
			}
			//cout<<res[i]<<" "<<dist[i]<<" "<<steps[i]<<" "<<weight[i]<<" "<<prex<<" "<<prey<<endl;
			prex = x;
			prey = y;
		}
		cout<<res[n]<<endl;
		if(ncase) cout<<endl;
	}

}
