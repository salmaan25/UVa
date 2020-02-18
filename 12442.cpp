#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define PI 3.1415926535897932384626433832795
int powmod(int a,int b,int mod) {int res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
typedef long long ll; typedef vector<ll> vi; typedef pair<ll, ll> ii; typedef vector<ii> vii;
#define pb push_back
int __set(int b, int i) {return b|(1<<i);} //set ith bit
int __unset(int b, int i) {return b&!(1<<i);}
int __check(int b, int i) {return b&(1<<i);} //returns 0 if ith bit is 0
const ll inf = 0xFFFFFFFFFFFFFFFL; //very large number
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
int adjlist[100000], cyclen[100000], chain[100000];

void dfs1(int node, vi& vis, int cur) {
	vis[node]=1; int tmp=0;
	int p=node, c=adjlist[node];
	stack<ii> s; s.push({p, tmp++});
	while(!vis[c]) {
		vis[c]=cur;
		s.push({c, tmp++});
		p=c;
		c=adjlist[c];
	}
	if(vis[c]!=cur)
		return;
	while((s.top()).ff != c)
		s.pop();
	int len=tmp-(s.top()).ss;
	chain[p]=len;
	while(c!=p) {
		chain[c]=len;
		c=adjlist[c];
	}
}

void dfs2(int node, vi& vis) {
	vis[node]=1;
	if(!vis[adjlist[node]])
		dfs2(adjlist[node], vis);
	chain[node]=chain[adjlist[node]]+1;
}
int32_t main(void)
{
	IOS;
	int t; cin>>t; int tc=0;
	while(++tc<=t) {
		int n; cin>>n;
		memset(chain, 0, sizeof(chain));
		memset(cyclen, 0, sizeof(cyclen));
		memset(adjlist, 0, sizeof(adjlist));
		for(int i = 0; i < n; i++) {
			int u, v; cin>>u>>v;
			adjlist[u-1]=v-1;
		}
		vi vis(n,0);
		int putv=1;
		for(int i = 0; i < n; i++) {
			if(!vis[i]) {
				dfs1(i, vis, putv);
				putv++;
			}
		}
		vis.assign(n, 0);
		for(int i = 0; i < n; i++) {
			if(chain[i] != 0)
				vis[i]=1;
		}
		for(int i = 0; i < n; i++) {
			if(!vis[i])
				dfs2(i, vis);
		}
		int mx = *max_element(chain, chain+n), ind=-1;
		for(int i = 0; i < n; i++) {
			if(chain[i]==mx) {
				ind=i;
				break;
			}
		}
		cout<<"Case "<<tc<<": "<<ind+1<<endl;
	}
	return 0;
}