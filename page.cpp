#include<vector>
#include<queue>
#include<string>
#include<algorithm>
#include<iostream>
#include<set>
#include<map>
#include<unordered_map>
#include<limits.h>
#include<iterator>
#include<stdio.h>
#include<stdlib.h>
#include<iomanip>
#include<random>
using namespace std;

map<int,vector<int> > graph;
bool visit[101];
int n;

int bfs(int node){
	queue<int> cur,next;
	fill_n(visit,101,false);
	cur.push(node);
	visit[node] = true;
	int level = 0;
	int sum=0;
	while(!cur.empty()){
		sum+= cur.size()*level;
		while(!cur.empty()){
			int a = cur.front();
			cur.pop();
			for(int b:graph[a]){
				if(!visit[b]){
					visit[b] = true;
					next.push(b);
				}
			}
		}
		swap(cur,next);
		level++;
	}
	return sum;
}

int main(){

	freopen("input","r+",stdin);
	int ncase = 0;
	while(1){
		ncase++;
		graph.clear();
		int a,b;
		while(1){
			cin>>a>>b;
			if(a==0) break;
			graph[a].push_back(b);
		}
		n = graph.size();
		if(n==0) break;
		double sum = 0;
		for(auto it:graph){
			sum += bfs(it.first);
		}

		double click = sum/n/(n-1);
		cout<<"Case "<<ncase;
		cout<<": average length between pages = "<<fixed<<setprecision(3)<<click<<" clicks"<<endl;



	}
	return 0;
}
