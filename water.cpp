#include<vector>
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<iomanip>
using namespace std;

struct Cistern{
	double base;
	double capacity;
	double height;
};

double volume(vector<Cistern>& cs,double h){
	double v = 0;
	for(auto c:cs){
		if(c.base<h){
			double p = (h-c.base>=c.height) ? 1:((h-c.base)/c.height);
			v+=p*c.capacity;
		}
	}
	return v;
}

int main(){


	//freopen("input","r+",stdin);
	int ncases;
	cin>>ncases;

	while(ncases--){
		int cnum;
		cin>>cnum;
		vector<Cistern> cs;
		double maxh=-1,total=0;
		while(cnum--){
			Cistern c;
			cin>>c.base;
			cin>>c.height;
			double w,d;
			cin>>w>>d;
			c.capacity = c.height*w*d;
			cs.push_back(c);
			total+=c.capacity;
			maxh = max(maxh,c.base+c.height);
		}

		double water;
		cin>>water;

		if(water>total) {cout<<"OVERFLOW"<<endl;if(ncases) cout<<endl;continue;}

		double e = 0.00001;
		double r = maxh;
		double l = 0,h;

		while(1){
			h = (r+l)/2;
			double v = volume(cs,h);
			if(abs(v-water)<e)
				break;
			else if((v-water)>e) r = h;
			else l=h;
		}

		cout<<fixed<<setprecision(2)<<h<<endl;
		if(ncases) cout<<endl;

	}
	return 0;
}
