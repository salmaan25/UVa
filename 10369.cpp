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
priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>> > pq; //for min priority_queue
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
clock_t time_p=clock();
void time()
{
    time_p=clock()-time_p;
    cerr<<"Time Taken : "<<(float)(time_p)/CLOCKS_PER_SEC<<"\n";
}
double dis(ii a, ii b) { return (double)sqrt((a.ff-b.ff)*(a.ff-b.ff)+(a.ss-b.ss)*(a.ss-b.ss)); } 
class UnionFind {
private:
	int n, disjcomp;
	vi p; vi rank; vi size;
public:
	UnionFind(int _n) {
		n=_n; disjcomp=n;
		p.assign(n, 0); rank.assign(n, 0); size.assign(n, 1);
		for(int i = 0; i < n; i++) p[i]=i;
	}
	int findSet(int a) {
		if(p[a]==a) return a;
		int b=findSet(p[a]);
		p[a]=b;
		return b;
	}
	bool isSameSet(int a, int b) {
		if(findSet(a) == findSet(b)) return true;
		return false;
	} 
	void unionSet(int a, int b) {
		if(!isSameSet(a,b)) {
			disjcomp--;
			int x = findSet(a), y = findSet(b);
			if(rank[x] > rank[y])
				p[y]=x;
			else {
				p[x]=y;
				if(rank[x]==rank[y])
					rank[y]++;
			}
			size[x] += size[y]; size[y] += size[x];
		}
	}
	int numDisjComp() {return disjcomp;}
};
int32_t main(void)
{
	// IOS;
	int t; cin>>t;
	while(t--) {
		int s, n; 
		cin>>s>>n;
		vector<ii> coord(n);
		for(int i = 0; i < n; i++)
			cin>>coord[i].ff>>coord[i].ss;
		int ct=0;
		vector<pair<double, ii>> edgelist;
		for(int i = 0; i < n; i++) {
			for(int j = i+1; j < n; j++) {
				edgelist.pb({dis(coord[i], coord[j]), {i, j}});
				pq.push({dis(coord[i], coord[j]), edgelist.size()-1});
			}
		}
		UnionFind uf(n); double ans=0.0;
		// cout<<"DONE"<<endl;	
		while(!pq.empty()) {
			pair<double, int> p = pq.top(); pq.pop();
			int u = edgelist[p.ss].ss.ff, v = edgelist[p.ss].ss.ss;
			// cout<<uf.numDisjComp()<<" "<<s<<" "<<uf.isSameSet(u, v)<<endl;
			if(!uf.isSameSet(u, v)) {
				if(uf.numDisjComp() > s) {
					// cout<<u<<" "<<v<<endl;
					uf.unionSet(u, v);
					ans = p.ff;
				}
			}
		}
		// int num = (int)ans; int d = (int)log10(num)+1;
		// if(double(num) != ans)
		// 	cout<<setprecision(d+2)<<ans<<endl;
		printf("%.2f\n", ans);
	}	
	time();	
	return 0;
}