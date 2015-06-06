#include<queue>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<stdlib.h>
#include<iostream>
#include<string.h>
#include<numeric>

using namespace std;

struct Edge{
	int start;
	int end;
	int weight;
	Edge(int s,int e,int w):start(s),end(e),weight(w){}
	bool operator<(const Edge a) const {
		return weight<a.weight;
	}
};
struct Son{
	int to;
	int weight;
	Son(int t,int w):to(t),weight(w){}
};
vector<vector<Son>> graph;
vector<Edge> es;
int n,m,q;
int sets[50002];

int find(int x){
	return x==sets[x]?x:sets[x]=find(sets[x]);
}
bool unionset(int x,int y){
	x = find(x);
	y = find(y);
	if(x==y) return false;
	else {
		sets[y]=x;
		return true;
	}
}
void kruskal(){
	sort(es.begin(),es.end());
	iota(sets,sets+n+1,0);
	graph.clear();
	graph.resize(n+1);
	for(int i=0;i<m;i++){
		if(unionset(es[i].start,es[i].end)){
			graph[es[i].start].push_back(Son(es[i].end,es[i].weight));
			graph[es[i].end].push_back(Son(es[i].start,es[i].weight));
		}
	}
}

bool visit[50002];
int father[50002],depth[50002],dist[50002];

void dfs(int r){
	visit[r] = true;
	for(auto i:graph[r]){
		if(!visit[i.to]){
			father[i.to]=r;
			depth[i.to] = depth[r]+1;
			dist[i.to]=i.weight;
			dfs(i.to);
		}

	}
}

int query(int x,int y){
	int danger=0;
	while(depth[x]>depth[y]){
		danger=max(danger,dist[x]);
		x = father[x];
	}
	while(depth[x]<depth[y]){
		danger=max(danger,dist[y]);
		y = father[y];
	}
	while(x!=y){
		danger=max(danger,dist[x]);
		danger=max(danger,dist[y]);
		x = father[x];
		y = father[y];
	}
	return danger;

}
int main(){
	freopen("input","r+",stdin);
	int ncase=0;
	while(cin>>n){
		cin>>m;
		es.clear();
		for(int i=0;i<m;i++){
			int s,e,w;
			cin>>s>>e>>w;
			es.push_back(Edge(s,e,w));
		}
		kruskal();
		father[1]=1;depth[1]=0;dist[1]=0;
		fill_n(visit,n+1,false);
		dfs(1);
		cin>>q;
		if(ncase) cout<<endl;
		for(int i=0;i<q;i++){
			int x,y;
			cin>>x>>y;
			cout<<query(x,y)<<endl;
		}
		ncase++;
	}
	return 0;
}
