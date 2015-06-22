#include<limits.h>
#include<iterator>
#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<iomanip>
#include<unordered_map>
#include <unordered_set>

using namespace std;

int main(){
	freopen("input","r+",stdin);
	int n,ncase=0;
	while(1){
		cin>>n;
		if(n==0) break;
		ncase;
		unordered_set<string> dict;
		int maxl = 0;
		for(int i =0;i<n;i++){
			string w;
			cin>>w;
			maxl = max(w.size(),maxl);
			dict.insert(w);
		}
		cout<<dict.size()<<endl;
		if(ncase) cout<<endl;

	}
}
