#include<vector>
#include<queue>
#include<string>
#include<algorithm>
#include<iostream>
#include<set>
#include<map>
#include<limits.h>
#include<iterator>
#include<stdio.h>
#include<stdlib.h>
#include<iomanip>
#include<random>
using namespace std;

struct Point{
	int x;
	int y;
	Point(int _x,int _y):x(_x),y(_y){}
};
int n,m,k;
vector<string> dict(200);
//set<string> dict;
vector<vector<char> > grid(40,vector<char>(40));


int dx[] = {-1,0,1,0,1,-1,1,-1};
int dy[] = {0,1,0,-1,1,-1,-1,1};

void dfs(int i,int j,vector<Point>& pos,int step,int d,string& word,vector<vector<bool> > &visit){
	if(step==word.size()){
		for(Point p:pos){
			visit[p.x][p.y]=true;
		}
		return;
	}
	if(i<0||j<0||i>=n||j>=m||word[step]!=grid[i][j]) return;
	pos.push_back(Point(i,j));
	dfs(i+dx[d],j+dy[d],pos,step+1,d,word,visit);
	pos.pop_back();
}

int main(){

	freopen("input","r+",stdin);
	while(cin>>n){
		cin>>m>>k;
		for(int i=0;i<k;i++){
			cin>>dict[i];
		}
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				cin>>grid[i][j];
		vector<vector<bool> > visit(n,vector<bool>(m,false));
		for(int w=0;w<k;w++){
			for(int i=0;i<n;i++)
				for(int j=0;j<m;j++){
					if(dict[w][0]==grid[i][j]){
						vector<Point> pos;
						for(int d=0;d<8;d++)
							dfs(i,j,pos,0,d,dict[w],visit);
					}
				}
		}
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++){
				if(!visit[i][j])
					cout<<grid[i][j];
			}
		cout<<endl;
	}
	return 0;
}
