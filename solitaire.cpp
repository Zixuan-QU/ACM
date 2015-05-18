
#include"test.h"
#include<vector>
#include<queue>
#include<string>
#include<algorithm>
#include<iostream>
#include<set>
#include<iterator>
#include<stdio.h>
#include<stdlib.h>
#include<iomanip>
using namespace std;

struct point{
	int x;
	int y;
};

int v[8] = {2097152,262144,32768,4096,512,64,8,1};
char visit[16777216];

bool cmp(const point &point1,const point &point2)
{
    if(point1.x != point2.x)
        return point1.x < point2.x;
    return point1.y < point2.y;
}

bool isVacant(vector<point>&pos,int x,int y){
	point p;
	p.x = x;p.y=y;

}

int getHash(vector<point>&pos){
	sort(pos.begin(),pos.end());
	int hash=0;
	for(int i =0;i<4;i++){
		hash<<=3;
		hash+=pos[i].x;
		hash<<=3;
		hash+=pos[i].y;
	}
	return hash;
}

void move(queue<int> &q,vector<point >&pos,int i){
	int x = pos[i].x,y=pos[i].y;

	if( x>0 ){
		if (isVacant(pos,x-1,y)){
			pos[i].x--;
			q.push(getHash(pos));
			pos[i].x++;
		}else if(x>1 && isVacant(pos,x-2,y)){
			pos[i].x+=2;
			q.push(getHash(pos));
			pos[i].x-=2;
		}
	}

	if( x<7 ) {
		if(isVacant(pos,x+1,y)){
			pos[i].x++;
			q.push(getHash(pos));
			pos[i].x--;
		} else if(x<6 && isVacant(pos,x+2,y)){
			pos[i].x+=2;
			q.push(getHash(pos));
			pos[i].x-=2;}
	}


	if( y>0 ) {
		if(isVacant(pos,x,y-1)){
			pos[i].y--;
			q.push(getHash(pos));
			pos[i].y++;
		}else if(y>1 && isVacant(pos,x,y-2)){
			pos[i].y-=2;
			q.push(getHash(pos));
			pos[i].y+=2;
		}
	}

	if( y<7) {
		if(isVacant(pos,x,y+1)){
			pos[i].y++;
			q.push(getHash(pos));
			pos[i].y--;
		}else if(y<6 && isVacant(pos,x,y+2)){
			pos[i].y+=2;
			q.push(getHash(pos));
			pos[i].y-=2;
		}
	}

}


int main(){

	freopen("input","r+",stdin);
	fill_n(visit,16777216,'0');

	int x,start=0,end=0;
	for(int i=0;i<8;i++){
		cin>>x;
		start<<=3;
		start+=(x-1);
	}
	for(int i=0;i<8;i++){
			cin>>x;
			end<<=3;
			end+=(x-1);
	}

	queue<int> cur,next;
	cur.push(start);

	vector<point> pos(4);
	int stepoint = 4;

	while(stepoint--){
		while(!cur.empty()){
			int state = cur.front();
			cur.pop();
			if(visit[state]=='1') continue;
			else visit[state] = '1';

			for(int i =0;i<4;i++){
				int y = state&7;
				state>>=3;
				int x = state&7;
				state>>=3;
				pos.push_back({x,y});
			}

			for(int i=0;i<4;i++){
				//move(next,state,pos,i);
			}
			pos.clear();
		}
		swap(next,cur);

	}

	cur = next;
	cur.push(end);
	stepoint = 4;

	while(stepoint--){
		while(!cur.empty()){
			int state = cur.front();
			cur.pop();

			if(visit[state]=='1') {
				cout<<"YES"<<endl;
				return 0;
			}
			else if(visit[state] =='2') continue;
			else visit[state] ='2';

			for(int i =0;i<4;i++){
				int y = state&7;
				state>>=3;
				int x = state&7;
				state>>=3;
				pos.push_back({x,y});
			}

			for(int i=0;i<4;i++){
				//move(next,state,pos,i);
			}

			pos.clear();
		}
		swap(next,cur);

	}

	cout<<"NO"<<endl;
	return 0;
}



