//similar to water shortage
//greedy + binary search
#include<algorithm>
#include<iostream>
#include<iterator>
#include<stdio.h>
#include<stdlib.h>
#include<iomanip>
using namespace std;

int n,m;
int houses[100000];

bool routers(double dist){
	double start = houses[0]+dist;
	int num=1;
	for(int i=0;i<n;i++){
		if(abs(houses[i]-start)>dist){
			num++;
			if(num>m) return false;
			start = houses[i]+dist;
		}
	}
	return true;
}

int main(){

	freopen("input","r+",stdin);
	int ncase;
	cin>>ncase;
	while(ncase--){
		cin>>m>>n;
		for(int i=0;i<n;i++)
			cin>>houses[i];

		sort(houses,houses+n);

		double r = (houses[n-1]-houses[0])/m,l =0,mid;
		while(r-l > 0.0001){
			mid = (r+l)/2;
			if(!routers(mid)) l = mid;
			else r = mid;
		}
		cout<<fixed<<setprecision(1)<<mid<<endl;
	}
	return 0;
}
