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
class UnionFind {
private:	
	int n, disjComp;
	vi rank; vi p; vi comp;
public:
	UnionFind(int _n) {
		n = _n; disjComp = n;
		rank.assign(n, 0); p.assign(n, 0); comp.assign(n, 1);
		for(int i = 0; i < n; i++) p[i]=i;
	}
	int findSet(int a) {
		if(p[a]==a) return a;
		int b = findSet(p[a]);
		p[a]=b;
		return b;
	}
	bool isSameSet(int a, int b) { return findSet(a)==findSet(b); }
	void unionSet(int a, int b) {
		if(!isSameSet(a, b)) {
			int x = findSet(a), y = findSet(b);
			if(rank[x] > rank[y])
				p[y]=x;
			else {
				p[x]=y;
				if(rank[x]==rank[y])
					rank[y]++;
			}
			comp[x] += comp[y]; comp[y] += comp[x];
		}
	}
};
int dfs(int u, vector<vii>& adjlist, vi& vis, int v) {
	vis[u]=1;
	if(u==v)
		return 0;
	for(int i = 0; i < adjlist[u].size(); i++) {
		int node = adjlist[u][i].ff;
		if(!vis[node]) {
			int x = dfs(node, adjlist, vis, v);
			if(x!=-1)
				return max(x, adjlist[u][i].ss);	
		}
	}
	return -1;
}
int32_t main(void)
{
	IOS;
	int tc=1;
	int n, m, q;
	cin>>n>>m>>q;
	while(!(!n && !m && !q)) {
		vector<pair<ii, int>> edgelist(m);
		for(int i = 0; i < m; i++) {
			cin>>edgelist[i].ff.ff>>edgelist[i].ff.ss>>edgelist[i].ss;
			edgelist[i].ff.ff--; edgelist[i].ff.ss--;
			pq.push({edgelist[i].ss, i});
		}
		vi taken(m, 0);
		UnionFind uf(n);
		while(!pq.empty()) {
			ii p = pq.top(); pq.pop();
			int u = edgelist[p.ss].ff.ff, v = edgelist[p.ss].ff.ss;
			if(!uf.isSameSet(u, v)) {
				uf.unionSet(u, v);
				taken[p.ss]=1;
			}
		}
		vector<vii> adjlist(n);
		for(int i = 0; i < m; i++) {
			if(taken[i]) {
				int u = edgelist[i].ff.ff, v = edgelist[i].ff.ss, c = edgelist[i].ss;
				adjlist[u].pb({v, c});
				adjlist[v].pb({u, c});
			}
		}
		cout<<"Case #"<<tc<<endl;
		while(q--) {
			int u, v; cin>>u>>v; u--; v--;
			vi vis(n, 0);
			int ans = dfs(u, adjlist, vis, v);
			if(ans==-1)
				cout<<"no path"<<endl;
			else cout<<ans<<endl;
		}
		cin>>n>>m>>q;
		if(!(!n && !m && !q))
			cout<<endl;
		tc++;
	}
	time();	
	return 0;
}