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
	int ncase;
	cin>>ncase;
	for(int c=1;c<=ncase;c++){
		string s,t;
		cin>>s>>t;
		int zero=0,one=0,qo=0,qz=0;
		for(int i = 0;i<s.size();i++){
			if(s[i]=='0' && t[i]=='1') zero++;
			else if(s[i]=='1' && t[i]=='0') one++;
			else if(s[i]=='?'&& t[i]=='1') qo++;
			else if(s[i]=='?'&& t[i]=='0') qz++;
		}

		printf("Case %d: %d\n",c,(one-zero>qo?-1:max(zero,one)+qo+qz));
	}
}
