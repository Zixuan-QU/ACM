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

void bfs(vector<vector<int> > &graph,vector<int> &visit,vector<int> father,int node,int &minl){

	visit[node] = 1;
	for(int i =0;i<graph[node].size();i++){
		if(visit[graph[node][i]]==1 && i!=father[node]){
			int tmp = node,l=1;
			while(tmp!=i){
				tmp = father[tmp];
				l++;
			}
			if(minl>l) minl = l;
		}
		else if(visit[graph[node][i]]==0){
			father[graph[node][i]]=node;
			bfs(graph,visit,father,graph[node][i],minl);
		}
	}
	visit[node] = 2;
}

int main(){

	freopen("input","r+",stdin);

	int ncases;
	cin>>ncases;
	int count=0;
	while(++count<=ncases){
		int t,p;
		cin>>t>>p;
		vector<vector<int> >graph(t);
		while(p--){
			int start,end;
			cin>>start>>end;
			graph[start].push_back(end);
			graph[end].push_back(start);
		}
		vector<int> visit(t,0);
		vector<int> father(t,-1);
		int minl = INT_MAX;
		for(int i = 0;i<t;i++){
			if(!visit[i])
				bfs(graph,visit,father,i,minl);
		}
		cout<<"Case "<<count<<": ";
		if(minl==INT_MAX) cout<<"impossible"<<endl;
		else cout<<minl<<endl;
		if(count!=ncases) cout<<endl;
	}
	return 0;
}
