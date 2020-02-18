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
priority_queue<pair<ii, ii>, vector<pair<ii, ii>>, greater<pair<ii, ii>> > pq; //for min priority_queue
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
clock_t time_p=clock();
void time()
{
    time_p=clock()-time_p;
    cerr<<"Time Taken : "<<(float)(time_p)/CLOCKS_PER_SEC<<"\n";
}
class UnionFind {                                                               // OOP style
	private: 
		vi p, rank, setCount;
		int NumSets;                                                            // remember: vi is vector<int>
	public:																		// setCount counts number of elements in a disjoint set
		UnionFind(int N) { 
			NumSets = N;
			rank.assign(N, 0);
			setCount.assign(N, 1);
			p.assign(N, 0); for (int i = 0; i < N; i++) p[i] = i; 
		}
		int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
		bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
		void unionSet(int i, int j) {
			if (!isSameSet(i, j)) {                                             // if from different set
				int x = findSet(i), y = findSet(j);
				NumSets--;
				if (rank[x] > rank[y]) {
					p[y] = x;                                                   // rank keeps the tree short
					setCount[x] += setCount[y]; }
				else { 
					p[x] = y;
					setCount[y] += setCount[x];
					if (rank[x] == rank[y]) rank[y]++; }
			} 
		}
		int SizeOfSet(int i) { return setCount[findSet(i)]; }
		int NumDisjointSets(){ return NumSets;} 
};
int32_t main(void)
{
	IOS;
	int n, m; cin>>n>>m;
	while(!(!n && !m)) {
		UnionFind uf(n);
		vector<pair<ii, int>> edgelist(m);
		vi taken(m, 0);
		for(int i = 0; i < m; i++) {
			int u, v, c; cin>>u>>v>>c;
			edgelist[i]={{u,v}, c};
			pq.push({{c,i}, {u,v}});
		}
		while(!pq.empty()) {
			pair<ii, ii> p = pq.top();  pq.pop();
			if(!uf.isSameSet(p.ss.ff, p.ss.ss)) {
				uf.unionSet(p.ss.ff, p.ss.ss);
				taken[p.ff.ss]=1;
			}
		}
		vi ans;
		for(int i = 0; i < m; i++) {
			if(!taken[i]) {
				ans.pb(edgelist[i].ss);
			}
		}
		// cout<<ans.size()<<endl;
		if(ans.size()) {
			sort(all(ans));
			for(int i = 0; i < ans.size(); i++) {
				if(i != ans.size()-1) cout<<ans[i]<<" ";
				else cout<<ans[i]<<endl;
			}
		}
		else 
			cout<<"forest"<<endl;
		cin>>n>>m;
	}
	time();	
	return 0;
}