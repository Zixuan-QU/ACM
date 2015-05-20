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


void dfs(vector<vector<char> >&graph,vector<int> cur,vector<int> option,vector<int> &result){
	int c;
	c = cur.back();

	int n = graph.size();
	for(auto it = option.begin();it!=option.end();it++){
		int e=*it;
		bool flag = true;
		for(int i=0;i<n;i++){
			if(graph[i][c]=='1' && graph[i][e]=='0'){
				for(auto next:option)
					if(graph[i][next]=='1'){
						flag = false;
						break;
					}
			}
			if(!flag) break;
		}
		if(flag){
			it = option.erase(it);
			cur.push_back(e);
			if(cur.size()==graph[0].size()) {result = cur;return;}
			else {
				dfs(graph,cur,option,result);
			}
			it = option.insert(it,e);
			cur.pop_back();
		}
	}
}

int main(){

	freopen("input","r+",stdin);
	int ncase;
	cin>>ncase;
	while(ncase--){
		int n,m;
		cin>>n>>m;
		vector<vector<char> > graph(n,vector<char>(m));
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				cin>>graph[i][j];
		vector<int> cur{0},result;
		vector<int> option(m-1);
		iota(option.begin(),option.end(),1);
		dfs(graph,cur,option,result);
		for(auto c:result){
			cout<<c<<endl;
		}
		if(ncase) cout<<endl;
	}
	return 0;
}
