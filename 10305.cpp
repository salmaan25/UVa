#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ff first
#define ss second
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define PI 3.1415926535897932384626433832795
int MOD=1e9+7;
int powmod(int a,int l, int md){int res=1;while(l){if(l&1)res=res*a%md;l/=2;a=a*a%md;}return res;}
typedef long long ll; typedef vector<ll> vi; typedef pair<ll, ll> ii; typedef vector<ii> vii;
#define pb push_back
int __set(int b, int i) {return b|(1<<i);} //set ith bit
int __unset(int b, int i) {return b&!(1<<i);}
int __check(int b, int i) {return b&(1<<i);} //returns 0 if ith bit is 0
int mul(int a, int b) {return ((a%MOD)*(b%MOD))%MOD;}
int add(int a, int b) {return (a+b)%MOD;}
int sub(int a, int b) {return (((a-b)%MOD)+MOD)%MOD;}
int __div(int a, int b) {return mul(a, powmod(b, MOD-2, MOD));} //if MOD is prime;
const ll inf = 0xFFFFFFFFFFFFFFFL; //very large number
priority_queue<int, vector<int>, greater<int> > pq; //for min priority_queue
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
clock_t time_p=clock();
void time()
{
    time_p=clock()-time_p;
    cerr<<"Time Taken : "<<(float)(time_p)/CLOCKS_PER_SEC<<"\n";
}
int32_t main(void)
{
	IOS;
	int n, m;
	cin>>n>>m;
	while(!(n==0 && m==0)) {
		vector<vi> adjlist(n);
		// for(int i = 0; i < m; i++)
		// vector<vi> adjlist(n);
		for(int i = 0; i < m; i++) {
			int v1, v2; cin>>v1>>v2;
			adjlist[v1-1].pb(v2-1);
		}
		// cout<<"good 1"<<endl;
		vi ind(n, 0);
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < adjlist[i].size(); j++) {
				ind[adjlist[i][j]]++;
			}
		}
		for(int i = 0; i < n; i++) {
			if(!ind[i])
				pq.push(i);
		}
		vi ans;
		while(!pq.empty()) {
			int v=pq.top(); pq.pop();
			ans.pb(v);
			for(int i = 0; i < adjlist[v].size(); i++) {
				int u = adjlist[v][i]; ind[u]--;
				if(!ind[u])
					pq.push(u);
			}
		}
		// vi vis(n, 0);
		// for(int i = 0; i < n; i++) {
		// 	if(!vis[i])
		// 		dfs(i, adjlist, vis, ans);
		// }
		for(int  i = 0; i < n; i++)
			cout<<ans[i]+1<<" ";
		cout<<endl;
		cin>>n>>m;
	}	
	time();	
	return 0;
}