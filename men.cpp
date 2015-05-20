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

bool vacant(vector<string>& road,vector<vector<int> >&sch,int x,int y,int t ){
	int n = road.size();
	if(x<0||x>=n||y<0||y>=n)
			return false;
	if(sch[x][y]==0) return road[x][y]=='.'?true:false;
	else return (t/sch[x][y])%2? (road[x][y]=='.'?false:true):(road[x][y]=='.'?true:false);
}

int findm(int a,int b){
	if(a>b) swap(a,b);
	if(!(b%a)) return b;
	int fa = a,fb=b;
	for(int i =a/2;i>=2;i--){
		if(!(fb%i) && !(fa%i)){
			fa/=i;
			fb/=i;
		}
	}
	return fa*b;
}


void visit(vector<string>& road,vector<vector<int> >&sch,queue<pair<int,int>> &next,vector<vector<vector<int>>> &visited,int x,int y,int t,int m){
	if(vacant(road,sch,x,y,t)){
		if(!visited[x][y].size()||(find_if(visited[x][y].begin(),visited[x][y].end(),[&m,&t](int e){return (t-e)%m == 0;})==visited[x][y].end())){
			next.push({x,y});
			visited[x][y].push_back(t);
		}
	}
	if(vacant(road,sch,x,y+1,t)){
			if(!visited[x][y+1].size()||(find_if(visited[x][y+1].begin(),visited[x][y+1].end(),[&m,&t](int e){return (t-e)%m == 0;})==visited[x][y+1].end())){
				next.push({x,y+1});
				visited[x][y+1].push_back(t);
			}
	}
	if(vacant(road,sch,x,y-1,t)){
			if(!visited[x][y-1].size()||(find_if(visited[x][y-1].begin(),visited[x][y-1].end(),[&m,&t](int e){return (t-e)%m == 0;})==visited[x][y-1].end())){
				next.push({x,y-1});
				visited[x][y-1].push_back(t);
			}
	}
	if(vacant(road,sch,x+1,y,t)){
				if(!visited[x+1][y].size()||(find_if(visited[x+1][y].begin(),visited[x+1][y].end(),[&m,&t](int e){return (t-e)%m == 0;})==visited[x+1][y].end())){
					next.push({x+1,y});
					visited[x+1][y].push_back(t);
				}
	}
	if(vacant(road,sch,x-1,y,t)){
				if(!visited[x-1][y].size()||(find_if(visited[x-1][y].begin(),visited[x-1][y].end(),[&m,&t](int e){return (t-e)%m == 0;})==visited[x-1][y].end())){
					next.push({x-1,y});
					visited[x-1][y].push_back(t);
				}
	}

}

int m;
int main(){

	freopen("input","r+",stdin);
	int n,ncase=0;
	while(cin>>n){
		vector<string> road;
		vector<vector<int>> sch(n);
		int num = n;
		while(n--){
			string s;
			cin>>s;
			road.push_back(s);
		}
		n=num;
		m=1;
		for(int i = 0;i<n;i++){
			for(int j =0;j<n;j++){
				char c;
				cin>>c;
				sch[i].push_back(c-'0');
				if(c!='0')
				m = findm(m,c-'0');
			}
		}
		vector<vector<vector<int>>> visited(n,vector<vector<int>>(n));

		queue<pair<int,int> > cur,next;
		cur.push({0,0});
		int t=0;
		bool flag=false;

		while(!cur.empty()){
			while(!cur.empty()){
				int i = cur.front().first;
				int j = cur.front().second;
				if(i==n-1 && j==n-1) {
					flag = true;
					break;
				}
				visit(road,sch,next,visited,i,j,t+1,m);
				cur.pop();
			}
			if(flag) break;
			swap(cur,next);
			t++;
		}
		if(ncase) cout<<endl;
		if(flag) cout<<t<<endl;
		else cout<<"NO"<<endl;
		ncase++;

	}
	return 0;
}
