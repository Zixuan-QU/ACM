//dp solution
//Some words have the same morse code, so we must not use set to record the dictionary, for which I waste a lot of time
#include<vector>
#include<string>
#include<algorithm>
#include<iostream>
#include<unordered_map>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

int main(){

	string morse[26] = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.",
			"....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-",
			".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." };

	//freopen("input","r+",stdin);
	int ncases;
	cin>>ncases;
	while(ncases--){
		string input;
		cin>>input;
		int size;
		cin>>size;
		unordered_map<string,int> dict;
		while(size--){
			string word,code;
			cin>>word;
			for(char c:word)
				code+= morse[c-'A'];

			dict[code]++;
		}
		size = input.size();
		vector<long> f(size+1,0);
		f[0]=1;
		for(int i =1;i<=size;i++)
			for(int j=i-1;j>=0;j--){
				if(f[j] && dict.find(input.substr(j,i-j))!=dict.end())
					f[i]+=f[j]*dict[input.substr(j,i-j)];
			}

		cout<<f[size]<<endl;
		if(ncases) cout<<endl;

	}


	return 0;
}

//dfs time limit exceeded
#include<vector>
#include<string>
#include<algorithm>
#include<iostream>
#include<unordered_set>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

void dfs(int pre,string &input,int &num,unordered_set<string> &dictionary){
	if(pre==input.size()) {
		num++;
		return;
	}
	for(int i =pre;i<input.size();i++){
	    if(dictionary.find(input.substr(pre,i-pre+1))!=dictionary.end())
	    	dfs(i+1,input,num,dictionary);
	}

}

int main(){

	string morse[26] = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.",
			"....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-",
			".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." };

	freopen("input","r+",stdin);
	int ncases;
	cin>>ncases;
	while(ncases--){
		string input;
		cin>>input;
		int size;
		cin>>size;
		unordered_set<string> dictionary;
		while(size--){
			string word,code;
			cin>>word;
			for(char c:word)
				code+= morse[c-'A'];

			dictionary.insert(code);
		}

		int num=0;
		dfs(0,input,num,dictionary);
		cout<<num;
		if(ncases>0) cout<<endl;

	}


	return 0;
}
