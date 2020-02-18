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
priority_queue<ii, vector<ii>, greater<ii> > pq; //for min priority_queue
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
	int t; cin>>t; int tc=0;
	while(tc++ < t) {
		int n, m, s, t; cin>>n>>m>>s>>t;
		vector<vii> adjlist(n);
		for(int i = 0; i < m; i++) {
			int u, v, c; cin>>u>>v>>c;
			adjlist[u].pb({v, c});
			adjlist[v].pb({u, c});
		}
		pq.push({0, s}); vi vis(n, inf); vis[s]=0;
		while(!pq.empty()) {
			ii p = pq.top(); pq.pop();
			int d = p.ff; int u = p.ss;
			if(d > vis[u])
				continue;
			for(int i = 0; i < adjlist[u].size(); i++) {
				ii v = adjlist[u][i];
				if(v.ss+vis[u] < vis[v.ff]) {
					vis[v.ff]=vis[u]+v.ss;
					pq.push({vis[v.ff], v.ff});
				}
			}
		}
		cout<<"Case "<<"#"<<tc<<": ";
		if(vis[t]==inf) cout<<"unreachable"<<endl;
		else cout<<vis[t]<<endl;
	}	
	time();	
	return 0;
}