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
	Point(int _x,int _y):x(_x),y(_y){}
};

struct Roof{
	Point start;
	Point end;
	bool left;
	int index;
	int v;
	Roof(int i,int sx,int sy,int ex, int ey):index(i),start(sx,sy),end(ex,ey){
		left = sy<ey?false:true;
		v=0;
	}
};

bool cmph(Roof a,Roof b){
	return (a.left?a.end.y:a.start.y) > (b.left?b.end.y:b.start.y);
}

bool cmpi(Roof a, Roof b){
	return a.index < b.index;
}

int main(){

	freopen("input","r+",stdin);
	int ncase;
	cin>>ncase;
	while(ncase--){
		int n;
		cin>>n;
		vector<Roof> roofs;
		for(int i=0;i<n;i++){
			int sx,sy,ex,ey;
			cin>>sx>>sy>>ex>>ey;
			roofs.push_back(Roof(i,sx,sy,ex,ey));
		}
		sort(roofs.begin(),roofs.end(),cmph);
		bool collect[n];
		fill_n(collect,n,false);
		int f[n];
		fill(f,f+n,0);
		f[0] = abs(roofs[0].end.x-roofs[0].start.x);
		roofs[0].v=f[0];
		for(int i=1;i<n;i++){
			int sx = roofs[i].start.x;
			int ex = roofs[i].end.x;
			vector<Point> ins{Point(sx,ex)};

			for(int j=i-1;(j>=0)&&(i-j<1000);j--){
				if(collect[j]) continue;
				int hsx = roofs[j].start.x;
				int hex = roofs[j].end.x;
				bool l = roofs[j].left;
				int x = l?hex:hsx;
				for(auto it=ins.begin();it!=ins.end();it++){
					auto p = *it;
					if(x>=p.x && x<=p.y){
						f[i]+=f[j];
						collect[j]=true;
					}
					if(hex<=p.x || hsx>=p.y)
						continue;
					else{
						ins.erase(it);
						if(hex<p.y && hex >p.x ) ins.push_back(Point(hex,p.y));
						if(hsx>p.x && hsx<p.y) ins.push_back(Point(p.x,hsx));
						break;
					}

				}
				if(ins.size()==0) break;
			}

			if(ins.size()!=0)
				for(auto p:ins)
					f[i]+=p.y-p.x;
			roofs[i].v = f[i];
		}

		sort(roofs.begin(),roofs.end(),cmpi);

		for(int k=0;k<n;k++){
	    	cout<<roofs[k].v<<endl;
	    }
		if(ncase) cout<<endl;
	}

	return 0;
}
