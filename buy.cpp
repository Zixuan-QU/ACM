#include<vector>
#include<queue>
#include<string>
#include<algorithm>
#include<iostream>
#include<set>
#include<limits.h>
#include<iterator>
#include<stdio.h>
#include<stdlib.h>
#include<iomanip>
#include<random>
using namespace std;

struct Node{
	int x;
	int y;
};

Node nodes[1001];

struct Edge{
	int start;
	int end;
	int len;
	Edge(int s,int e):start(s),end(e){
		setlen();
	}
	void setlen(){
		len = (nodes[start].x-nodes[end].x)*(nodes[start].x-nodes[end].x)+(nodes[start].y-nodes[end].y)*(nodes[start].y-nodes[end].y);
	}
};

struct cmp{
	bool operator()(Edge a,Edge b ){
		return a.len<b.len;
	}
} mycmp;

int find(int node,vector<int> &trees){

	return trees[node]==node?node:trees[node]=find(trees[node],trees);
}

bool unionTrees(int start,int end,vector<int> &trees){
	start = find(start,trees);
	end = find(end,trees);
	if(start == end) return false;
	else {
		trees[end] = start;
		return true;
	}
}

int kruskal(vector<int> &trees, vector<Edge> &edges){
	int total = 0;
	for(auto e:edges){
		if(unionTrees(e.start,e.end,trees))
			total += e.len;

	}
	return total;
}



int main(){

	freopen("input","r+",stdin);
	int ncase;
	cin>>ncase;
	while(ncase--){
		int n,q;
		cin>>n>>q;
		int costs[q];
		vector<int> subnet[q];
	    for(int i=0;i<q;i++){
	    	int cities;
	    	cin>>cities;
	    	cin>>costs[i];
	    	while(cities--){
	    		int city;
	    		cin>>city;
	    		subnet[i].push_back(city);
	    	}
	    }

	    for(int i =1;i<=n;i++){
	    	cin>>nodes[i].x;
	    	cin>>nodes[i].y;
	    }
	    vector<Edge> edges;

	    for(int i =1;i<=n;i++){
	    	for(int j =i+1;j<=n;j++){
	    		Edge e(i,j);
	    		edges.push_back(e);
	    	}
	    }
	    sort(edges.begin(),edges.end(),mycmp);

	    int result=INT_MAX;
	    vector<bool> select(q,0);
	    vector<int> trees(n+1);

	    for(int i = 0;i<=q;i++){
	    	fill(select.begin(),select.end(),0);
	    	fill_n(select.begin(),i,1);

	    	do{
	    		int buy=0;
	    		iota(trees.begin(),trees.end(),0);
	    		for(int s=0;s<q;s++){
	    			if(select[s]){
	    				buy+=costs[s];
	    				for(int j=1;j<subnet[s].size();j++)
	    					unionTrees(subnet[s][0],subnet[s][j],trees);
	    			}
	    		}

	    		result = min(buy+kruskal(trees,edges),result);


	    	}while(prev_permutation(select.begin(),select.end()));
	    }

	    cout<<result<<endl;
	    if(ncase) cout<<endl;
	}

	return 0;
}
