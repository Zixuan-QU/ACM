//Solution 1


//Solution 2
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

const double pi = acos(-1.0);

struct Point{
	int x;
	int y;
	int z;
}bs,be;

double distance(Point a,Point b){
	return sqrt((double)((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z)));
}

double vbox(){
	return abs((bs.x-be.x)*(bs.y-be.y)*(bs.z-be.z));
}

double minboxR(Point p){
	double xr = min(abs(p.x-bs.x),abs(p.x-be.x));
	double yr = min(abs(p.y-bs.y),abs(p.y-be.y));
	double zr = min(abs(p.z-bs.z),abs(p.z-be.z));
	double r = min(xr,yr);
	r = min(r,zr);
	return r;
}
int main(){

	freopen("input","r+",stdin);
	int ncase=0;
	int n;
	while(1){
		cin>>n;
		if(!n) break;

		cin>>bs.x>>bs.y>>bs.z;
		cin>>be.x>>be.y>>be.z;

		vector<Point> ps(n);
		for(int i =0;i<n;i++){
			cin>>ps[i].x>>ps[i].y>>ps[i].z;
		}
		vector<int> order(n);
		iota(order.begin(),order.end(),0);
		double result=0;

		do{
			double volume=0;
			vector<double> radix(n,0);
			for(int i=0;i<n;i++){
				Point p = ps[order[i]];
				double r = minboxR(p);
				for(int j=i-1;j>=0;j--){
					if(radix[j]==0) continue;
					Point f = ps[order[j]];
					if(distance(p,f)>radix[j]){
						r = min(r,distance(p,f)-radix[j]);
					} else {
						r = 0;
						break;
					}
				}
				if(r){
				radix[i] = r;
				volume += pi*r*r*r*4.0/3.0;
				}
			}
			result = max(result,volume);
		}while(next_permutation(order.begin(),order.end()));

		ncase++;
		cout<<"Box "<<ncase<<": "<<round(vbox()-result)<<endl;
		cout<<endl;
	}

	return 0;
}
