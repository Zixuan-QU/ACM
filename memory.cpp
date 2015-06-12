#include<limits.h>
#include<iterator>
#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<iomanip>
#include<unordered_map>

using namespace std;

int n,k;
unordered_map<char,int> people;

int main(){
	freopen("input","r+",stdin);
	int ncases,ncase = 0;
	cin>>ncases;
	while(ncases--){
		ncase++;
		people.clear();
		cin>>n>>k;
		int cnt=0;
		for(int i =0;i<n;i++){
			char p;
			cin>>p;
			if(people[p]>0) cnt++;
			for(auto it:people){
				people[it.first]--;
			}
			people[p]=k;
		}
		cout<<"Case "<<ncase<<": "<<cnt<<endl;
	}
}
