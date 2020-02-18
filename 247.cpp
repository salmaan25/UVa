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

class tarjanscc {
private:
	int n, m, sz, tm;
	vector<vi> adjlist;
	vector<vi> adjlist1;
	vector<vi> comp; 
	vi vis; vi fv; vi lv;
	void dfs(int u) {
		fv[u]=tm;
		tm+=1;
		vis[u]=1;
		for(int i = 0; i < adjlist[u].size(); i++) {
			int v = adjlist[u][i];
			if(!vis[v])
				dfs(v);
		}
		lv[u]=tm;
		tm+=1;
	}
	void dfs1(int u) {
		comp[sz].pb(u);
		vis[u]=1;
		for(int i = 0; i < adjlist1[u].size(); i++) {
			int v = adjlist1[u][i];
			if(!vis[v]) {
				dfs1(v);
			}
		}
	}
public:
	tarjanscc (int vct, int ect, vector<vi>& adjlistt) {
		n=vct; m=ect; sz=0; tm=0;
		adjlist.resize(n); adjlist1.resize(n); comp.resize(n); 
		vis.resize(n, 0); fv.resize(n, 0); lv.resize(n, 0);
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < adjlistt[i].size(); j++) {
				adjlist[i].pb(adjlistt[i][j]);
				adjlist1[adjlistt[i][j]].pb(i);
			}
		}
	}
	void findscc() {
		for(int i = 0; i < n; i++) {
			if(!vis[i])
				dfs(i);
		}
		fill(vis.begin(), vis.begin()+n, 0);
		priority_queue<ii> pq;
		for(int i = 0; i < n; i++)
			pq.push({lv[i], i});
		while(!pq.empty()) {
			ii u = pq.top(); pq.pop();
			if(!vis[u.ss]) {
				dfs1(u.ss);
				sz++;
			}
		}
	}
	int getcomp(vector<vi>& comp1) {
		for(int i = 0; i < sz; i++) {
			for(int j = 0; j < comp[i].size(); j++) {
				comp1[i].pb(comp[i][j]);
			}
		}
		return sz;
	}
};
int32_t main(void)
{
	IOS;
	int t=1;
	int n, m;
	cin>>n>>m;
	while(!(!n && !m)) {
		if(t!=1)
			cout<<endl;
		set<string> s;
		vector< pair<string, string> > st;
		for(int i = 0; i < m; i++) {
			string u, v; cin>>u>>v;
			if(s.find(u) == s.end())
				s.insert(u);
			if(s.find(v) == s.end())
				s.insert(v);
			st.pb({u, v});
		}
		vector<vi> adjlist(n);
		map<string, int> age; map<int, string> piche;
		int tmp=0;
		for(auto it=s.begin(); it!=s.end(); it++) {
			age[*it]=tmp;
			piche[tmp]=*it;
			tmp++;
		}
		for(int i = 0; i < m; i++) {
			auto it1= age.find(st[i].ff); auto it2= age.find(st[i].ss);
			adjlist[it1->second].pb(it2->second);
		}
		tarjanscc tc(n, m, adjlist);
		tc.findscc();
		vector<vi> comp(n);
		int sz = tc.getcomp(comp);
		cout<<"Calling circles for data set "<<t<<":"<<endl;
		for(int i = 0; i < sz; i++) {
			for(int j = 0; j < comp[i].size(); j++) {
				auto it=piche.find(comp[i][j]);
				cout<<it->second;
				if(j != comp[i].size()-1) {
					cout<<", ";
				} else {
					cout<<endl;
				}
			}	
		}
		cin>>n>>m;
		t++;
	}
	time();	
	return 0;
}