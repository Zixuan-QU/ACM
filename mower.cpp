#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<stdio.h>
using namespace std;

int main(){

	//freopen("input","r+",stdin);
	while(1){
		int nx,ny;
		double w;
		cin>>nx>>ny>>w;
		if(nx==0) break;

		vector<double> ends,sides;
		for(int i=0;i<nx;i++){
			double x;
			cin>>x;
			ends.push_back(x);
		}
		for(int i=0;i<ny;i++){
			double y;
			cin>>y;
			sides.push_back(y);
		}

		sort(ends.begin(),ends.end());
		sort(sides.begin(),sides.end());

		bool flag=true;

		for(int i = 0;i<=nx;i++){
			double end = (i==0? 0:ends[i-1]+w/2);
			double front = (i==nx? 75.0:ends[i]-w/2);
			if(front>end) {
				cout<<"NO"<<endl;
				flag = false;
				break;
			}
		}

		if(!flag) continue;

		for(int i = 0;i<=ny;i++){
			double end = (i==0? 0:sides[i-1]+w/2);
			double front = (i==ny? 100.0:sides[i]-w/2);
			if(front>end) {
				cout<<"NO"<<endl;
				flag = false;
				break;
			}
		}

		if(flag) cout<<"YES"<<endl;

	}
	return 0;
}
