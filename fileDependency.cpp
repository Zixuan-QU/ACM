#include<vector>
#include<queue>
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;


int main(){

	freopen("input","r+",stdin);
	int ncases;
	cin>>ncases;
	while(ncases--){
		int n,rules;
		cin>>n>>rules;

		vector<vector<int> > depend(n+1);
		vector<int> pre(n+1,0);

		while(rules--){
			int target,k,task;
			cin>>target>>k;
			pre[target]=k;
			while(k--){
				cin>>task;
				depend[task].push_back(target);
			}
		}

		priority_queue<int,vector<int>, greater<int> > pq;
		vector<int> result;

		for(int i =1;i<=n;i++)
			if(!pre[i]) pq.push(i);

		while(!pq.empty()){
			int node = pq.top();
			pq.pop();
			result.push_back(node);
			for(int s:depend[node]){
				pre[s]--;
				if(!pre[s]) pq.push(s);
			}
		}

		for(auto t:result){
			cout<<t;
			if(t==result.back())
				cout<<endl;
			else cout<<" ";
		}
		if(ncases) cout<<endl;

	}
	return 0;
}
