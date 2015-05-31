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

struct Point{
	int x;
	int y;
	Point():x(-1),y(-1){}
	Point(int _x,int _y):x(_x),y(_y){}
};

char plan[102][102];

Point enter;
int n,m;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
int check(int x,int y){
	if(x<0||x>n||y<0||y>m) return -1;
	if(plan[x][y]=='#') return 0;
	else if (plan[x][y]=='.') return 1;
	else return 2;
}

bool isCenter(int x,int y){
	if(check(x+1,y)==1 && check(x,y+1)==1&& check(x+1,y+1)==1) return true;
	if(check(x-1,y)==1 && check(x,y-1)==1&& check(x-1,y-1)==1) return true;
	if(check(x-1,y)==1 && check(x,y+1)==1&& check(x-1,y+1)==1) return true;
	if(check(x+1,y)==1 && check(x,y-1)==1&& check(x+1,y-1)==1) return true;
	else return false;
}

void findEnter(){
	Point s(0,0);
	plan[0][0]='*';
	queue<Point> q;
	q.push(s);
	while(!q.empty()){
		Point p = q.front();
		int x = p.x;
		int y = p.y;
		q.pop();
		if(((!check(x-1,y)) && (!check(x+1,y))) || ((!check(x,y-1)) && (!check(x,y+1)))){
			enter.x = x;
			enter.y = y;
			return;
		}
		for(int i=0;i<4;i++){
			int nx = x+dx[i];
			int ny = y+dy[i];
			if(check(nx,ny)==1){
				plan[nx][ny] = '*';
				q.push(Point(nx,ny));}
		}
	}
}

void dfs(int x, int y,int pre, bool &result){
	if(result) return;
	if(isCenter(x,y)){
		result = true;
		return;
	}
	for(int i=3;i<6;i++){
		int di = (pre+i)%4;
		int nx = x+dx[di];
		int ny = y+dy[di];
		if(check(nx,ny)==1){
			//cout<<nx<<" " <<ny<<endl;
			dfs(nx,ny,di,result);
			break;
		}
	}

}

int main(){

	freopen("input","r+",stdin);
	int ncase;
	cin>>ncase;	
	while(ncase--){
		cin>>n>>m;
		fill_n(&plan[0][0],102*102,'.');
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				cin>>plan[i][j];
		findEnter();
		bool result=false;
		dfs(enter.x,enter.y,0,result);
		cout<<(result?"YES":"NO")<<endl;
		if(ncase) cout<<endl;
	}

	return 0;
}
