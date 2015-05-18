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

int main(){

	freopen("input","r+",stdin);

	int ncases;
	cin>>ncases;

	while(ncases--){
		int x;
		cin>>x;
		vector<vector<int> > graph(x);
		while(x--){
			int c,nc;
			cin>>c>>nc;
			while(nc--){
				int f;
				cin>>f;
				graph[c].push_back(f);
			}
		}

		int start,end,level=0;
		cin>>start>>end;

		queue<int> cur,next;
		cur.push(start);
		bool flag = false;

		vector<bool> visit(graph.size(),false);

		while(!cur.empty()){
			while(!cur.empty()){
				int node = cur.front();
				cur.pop();
				for(auto f:graph[node]){
					if(f==end) {
						flag = true;
						break;
					}
					if(!visit[f]){
						next.push(f);
					}
				}
				if(flag) break;
				visit[node] = true;
			}
			if(flag) break;
			swap(cur,next);
			level++;
		}

		cout<<start<<" "<<end<<" "<<level<<endl;
		if(ncases) cout<<endl;
	}

	return 0;

}
