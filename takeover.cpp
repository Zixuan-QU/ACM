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

int n,m;
int A[100000],B[100000];

int win(int A[],int &a,int B[],int &b){
	if(a==0 && b==0) return A[a]>B[b];
	if(b==0) return A[a]+A[a-1]>B[b];
	if(a==0) return A[a]>B[b];
	if(A[a]+A[a-1]>B[b]+B[b-1])
		return 1;
	if(A[a]>B[b]) {
		b--;
		return -1;
	}
	if(A[a]>B[b-1]){
		B[b-1] = B[b];
		b--;
		return -1;
	}
	return 0;


}


int main(){
        freopen("input","r+",stdin);
        int ncase=0;
        while(cin>>n){
        		ncase++;
                cin>>m;
                for(int i =0;i<n;i++){
                	cin>>A[i];
                }
                for(int i =0;i<m;i++){
                	cin>>B[i];
                }
                sort(A,A+n);
                sort(B,B+m);
                int a = n-1,b=m-1;
                string winner;
                while(a>=0&&b>=0){
                	int o = win(A,a,B,b);
                	if(o==1){
                		winner = "Takeover Incorporated";
                		break;
                	}else if(o==0){
                		winner = "Buyout Limited";
                		break;
                	}else{
                		o=win(B,b,A,a);
                		if(o==1){
                			winner = "Buyout Limited";
                			break;
                		}else if(o==0){
                			winner = "Takeover Incorporated";
                			break;
                		}
                	}
                }

                //cout<<"Case "<<ncase<<": "<<winner<<endl;
                printf("Case %d: %s\n",ncase,winner.c_str());

        }
        return 0;
}
