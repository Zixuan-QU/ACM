#include<vector>
#include<queue>
#include<string>
#include<algorithm>
#include<iostream>
#include<unordered_map>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

struct Node{
	int node;
	Node* next;
};

int main(){

	//freopen("input","r+",stdin);
	int ncases;
	cin>>ncases;
	while(ncases--){
		int n,e,t,m;
		cin>>n>>e>>t>>m;

		vector<vector<int> > maze(n+1,vector<int>(n+1,0));

		while(m--){
			int start,end,cost;
			cin>>start>>end>>cost;
			maze[start][end]=cost;
		}

        vector<int> result(n+1,0);

		for(int i = 1;i<=n;i++){
			queue<pair<int,int> > q;
			q.push({i,0});
			vector<bool> visit(n+1,false);
			while(!q.empty()){
				int node = q.front().first;
				int cur = q.front().second;
				q.pop();
				//cout<<node<<" ";

				if(node == e) {
					if(cur<=t)
						result[i] = cur;
					break;
				}

				if(cur>=t) continue;

				for(int j = 1; j<=n; j++){
					if(maze[node][j] && !visit[j]){
						q.push(make_pair(j,cur+maze[node][j]));
					}
				}

				visit[node] = true;
			}

		}

		cout<<count_if(result.begin(),result.end(),bind2nd(greater<int>(),0))+1<<endl;
		if(ncases) cout<<endl;
	}
	return 0;
}
