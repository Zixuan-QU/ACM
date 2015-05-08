#include<vector>
using namespace std;

void dfs(int pre, int amount,int coin,bool &flag,vector<int> &coins){
	if(flag) return;
	if(!amount) {
		flag = true;
		return;
	}
	if(coin>=coins.size()) return;
	int num=0;
	while((amount-=coins[coin])>=0 && (++num)<=pre)
		dfs(num,amount,coin+1,flag,coins);

}

int main(){

	freopen("input","r+",stdin);
	int ncases;
	cin>>ncases;
	while(ncases--){
		int amount;
		cin>>amount;
		int n,coin;
		cin>>n;
		vector<int> coins;
		while(n--){
			cin>>coin;
			coins.push_back(coin);
		}
		bool flag = false;

		dfs(INT_MAX,amount,0,flag,coins);

		if(!flag) cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
		if(ncases>0) cout<<endl;
	}


	return 0;
}
