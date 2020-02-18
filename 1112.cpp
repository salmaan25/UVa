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
priority_queue<pair<int, ii>, vector<pair<int, ii>>, greater<pair<int, ii>> > pq; //for min priority_queue
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
clock_t time_p=clock();
void time()
{
    time_p=clock()-time_p;
    cerr<<"Time Taken : "<<(float)(time_p)/CLOCKS_PER_SEC<<"\n";
}
int dx[] = {0, 0, 1, -1}, dy[]={1, -1, 0, 0};
int32_t main(void)
{
	IOS;
	int t; cin>>t;
	while(t--) {
		int n, m; cin>>n>>m;
		int mat[n][m];
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++)
				cin>>mat[i][j];
		}
		pq.push({mat[0][0], {0, 0}});
		int vis[n][m];
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++)
				vis[i][j]=inf;
		}
		vis[0][0]=mat[0][0];
		while(!pq.empty()) {
			pair<int, ii> p;
			p = pq.top(); pq.pop();
			ii u = p.ss; int d = p.ff;
			if(d > vis[u.ff][u.ss])
				continue;
			for(int i = 0; i < 4; i++) {
				ii v = {u.ff+dx[i], u.ss+dy[i]};
				if(v.ff<n && v.ff>=0 && v.ss<m && v.ss>=0) {
					if(vis[v.ff][v.ss] <= vis[u.ff][u.ss]+mat[v.ff][v.ss]) {
						continue;
					}
					vis[v.ff][v.ss]=vis[u.ff][u.ss]+mat[v.ff][v.ss];
					pq.push({vis[v.ff][v.ss], v});
				}
			}
		}
		cout<<vis[n-1][m-1]<<endl;
	}	
	time();	
	return 0;
}