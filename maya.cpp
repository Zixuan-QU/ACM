#include<vector>
#include<queue>
#include<string>
#include<algorithm>
#include<iostream>
#include<unordered_map>
#include<iterator>
#include<stdio.h>
#include<stdlib.h>
using namespace std;


string haab[19] = {"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol",
			"chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu","uayet"};
string tzo[20] = {"imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik",
			"lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"};

int getMonth(string s){
	for(int i =0;i<19;i++){
		if(s==haab[i]) return i;
	}
}

int getDay(string s){
	for(int i =0;i<20;i++){
		if(s==tzo[i]) return i;
	}
}
int main(){


	freopen("input","r+",stdin);
	int ncases;
	cin>>ncases;
	cout<<ncases<<endl;
	while(ncases--){
		int day,year,month;
		string m;
		cin>>day;
		getchar();
		cin>>m; month = getMonth(m);
		cin>>year;
		int total = 365*year+month*20+day;
		int y = total /260;
		total%=260;
		int dayName=total%20;
		int dayNum = total%13+1;

		string dn = tzo[getDay("imix")+dayName];

		cout<< dayNum<<" "<<dn<<" "<<y<<endl;



	}
	return 0;
}
