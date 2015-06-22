#include<limits.h>
#include<iterator>
#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<iomanip>
#include<unordered_map>

using namespace std;

int main(){
	freopen("input","r+",stdin);
	int ncase;
	cin>>ncase;
	while(ncase--){
		int n,nc;
		cin>>n>>nc;
		unordered_map<string,int> dict;
		string text;
		cin>>text;
		for(int i =0;i<=text.size()-n;i++){
			string sub = text.substr(i,n);
			dict[sub]++;
		}
		cout<<dict.size()<<endl;
		if(ncase) cout<<endl;

	}
}
