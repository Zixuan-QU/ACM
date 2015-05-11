#include<vector>
#include<map>
#include<stack>
#include<cmath>
#include<string>
#include<algorithm>
#include<limits.h>
#include<cstring>
#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<iterator>
#include<stdio.h>
#include<stdlib.h>
#include<sstream>
#include<set>
using namespace std;

int main(){

	//freopen("input","r+",stdin);
	int n;
	vector<int> cases;
	while(cin>>n){
		cases.push_back(n);
	}
	int size = *max_element(cases.begin(),cases.end());
	vector<bool> primes(size+1,true);
	primes[0]=false;primes[1] = false;
	for(int i=2;i<=size/2;i++){
		if(primes[i]) {
			int j = i;
			while((j+=i)<=size){
			    primes[j]=false;
			}
		}
	}

	for(auto x:cases){
		for(int i =1;i<x;i++){
			if(primes[i] && primes[x-i]){
				cout<< x << " = "<<i<<" + "<<x-i<<endl;
				break;
			}

		}
	}


	return 0;
}
