#include<limits.h>
#include<iterator>
#include<stdlib.h>
#include<stdio.h>
#include<vector>
#include<iterator>
#include<algorithm>
#include<iostream>
#include<iomanip>
#include<unordered_map>

using namespace std;

int n,l;
bool visit[100000];
vector<int> item;



int main(){
        freopen("input","r+",stdin);
        int ncase;
        cin>>ncase;
        while(ncase--){
                cin>>n>>l;
                item.resize(n);
                for(int i =0;i<n;i++){
                        cin>>item[i];
                }
                sort(item.begin(),item.end());
                //fill_n(visit,n,false);
                int res = 0;
                for(auto i =item.begin();i!=item.end();i++){
                        if(i==prev(item.end())) {res++;break;}
                        int target = l-(*i);
                        if(target<*i) {
                        	//cout<<*i<<endl;
                        	res+= item.size() - distance(item.begin(),i);
                        	break;
                        }
                        auto j = lower_bound(i+1,item.end(),target);
                        if(j == item.end())
                        	item.erase(prev(item.end()));
                        else {
                        	if((*j)>target)
                        		j--;
                        	if(j!=i)
                        		item.erase(j);
                        }
                        res++;
                }
                cout<<res<<endl;
                if(ncase) cout<<endl;

        }
        return 0;
}
