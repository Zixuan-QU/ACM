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
using namespace std;

void dfs(vector<vector<int> > &graph,vector<int> &depth,int father,int level,int node,int &minl){
	depth[node] = level;
	for(auto v : graph[node]){
		if(v==father) continue;
		if(depth[v]!=-1){
			if(depth[v]<level)
				minl= min(minl,level-depth[v]+1);
			else if(depth[v]>level+1)
				dfs(graph,depth,node,level+1,v,minl);
		}else
			dfs(graph,depth,node,level+1,v,minl);

	}
}

int main(){

	freopen("input","r+",stdin);

	int ncases;
	scanf("%d", &ncases);
	int count=0;
	while(++count<=ncases){
		int t,p;
		scanf("%d", &t);
		scanf("%d", &p);
		vector<vector<int> >graph(t);
		while(p--){
			int start,end;
			scanf("%d", &start);
			scanf("%d", &end);
			graph[start].push_back(end);
			graph[end].push_back(start);
		}
		vector<int> depth(t,-1);
		int minl = INT_MAX;
		for(int i = 0;i<t;i++){
			if(depth[i]==-1)
				dfs(graph,depth,-1,1,i,minl);
		}
		printf("Case %d: ",count);
		if(minl==INT_MAX) printf("impossible\n");
		else printf("%d\n",minl);
	}
	return 0;
}
