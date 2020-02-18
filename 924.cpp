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
	int n; cin>>n;
	vector<vi> adjlist(n);
	for(int i = 0; i < n; i++) {
		int num; cin>>num;
		for(int j = 0; j < num; j++) {
			int u; cin>>u;
			adjlist[i].pb(u);
		}
	}
	int t; cin>>t;
	while(t--) {
		int u; cin>>u;
		vi vis(n, inf); vis[u]=0;
		queue<int> q; q.push(u);
		while(!q.empty()) {
			int v = q.front(); q.pop();
			for(int i = 0; i < adjlist[v].size(); i++) {
				int node = adjlist[v][i];
				if(vis[node]==inf) {
					vis[node]=min(vis[node], vis[v]+1);
					q.push(node);
				}
			}
		}
		int mx=-1;
		for(int i = 0; i < n; i++) {
			if(vis[i]!=inf)
				mx=max(mx, vis[i]);
		}
		vi ar(mx+1, 0);
		for(int i = 0; i < n; i++) {
			if(vis[i]!=inf) {
				ar[vis[i]]++;
			}
		}
		int fn = *max_element(all(ar));
		int o2=-1;
		for(int i = 1; i <= mx; i++) {
			if(fn==ar[i]) {
				o2=i;
				break;
			}
		}
		if(o2==-1)
			cout<<0<<endl;
		else cout<<fn<<" "<<o2<<endl;
	}
	time();	
	return 0;
}