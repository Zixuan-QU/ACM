#include<vector>
#include<queue>
#include<string>
#include<algorithm>
#include<iostream>
#include<set>
#include<limits.h>
#include<iterator>
#include<stdio.h>
#include<stdlib.h>
#include<iomanip>
#include<random>
using namespace std;

int dfs(vector<vector<int> > &graph,vector<int> &color,int node,int build,int& num){
	int result= build==1?1:0;
	num++;
	color[node] = build;
	for(int n:graph[node]){
		if(color[n]==build) return -1;
		if(color[n]==0){
			int r = dfs(graph,color,n,-build,num);
			if(r==-1) return -1;
			else result+= r;
		}
	}
	return result;
}

int main(){

	freopen("input","r+",stdin);
	int n,m;
	while(cin>>n){
		cin>>m;
		vector<vector<int> > graph(n+1);
		vector<int> color(n+1,0);
		while(m--){
			int start,end;
			cin>>start>>end;
			graph[start].push_back(end);
			graph[end].push_back(start);
		}
		bool flag=true;
		int result=0;
		for(int i=1;i<=n;i++){
			if(color[i]==0 && graph[i].size()){
				int num = 0;
				int r = dfs(graph,color,i,true,num);
				if(r == -1){
					flag = false;
					break;
				}else{
					result+=min(num-r,r);
				}
			}
		}
		if(flag) cout<<result<<endl;
		else cout<<"Impossible"<<endl;

	}

}
