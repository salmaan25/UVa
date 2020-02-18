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
int dx[]={0, 0, 1, -1}, dy[]={1, -1, 0, 0};
int32_t main(void)
{
	// IOS;
	int n, m;
	while(scanf("%lld %lld", &n, &m)==2) {
		// cin>>n>>m;
		// cout<<n<<" "<<m<<endl;
		int r; cin>>r;
		int mat[n*m][n*m];
		for(int i = 0; i < n*m; i++) {
			for(int j = 0; j < n*m; j++)
				mat[i][j]=inf;	
		}
		for(int i = 0; i < n*m; i++) {
			int r = i/m, c = i-r*m;
			for(int j = 0; j < 4; j++) {
				int u = r+dx[j], v = c+dy[j];
				if(u < n && u >= 0 && v < m && v >= 0)
					mat[i][u*m+v]=1;
			}
		}
		for(int i = 0; i < r; i++) {
			int a, b, c, d; cin>>a>>b>>c>>d;
			mat[a*m+b][c*m+d]=inf;
		}
		int q; cin>>q;
		int tim[n*m][510];
		for(int i = 0; i < n*m; i++) {
			for(int j = 0; j < 510; j++)
				tim[i][j]=0;
		}
		for(int i = 0; i < q; i++) {
			int ti, a, b; cin>>ti>>a>>b;
			tim[a*m+b][ti]=1;
		}
		vi dis(n*m, inf); dis[0]=0;
		pq.push({0, 0});
		// for(int i = 0; i < n*m; i++) {
		// 	for(int j = 0; j < n*m; j++)
		// 		cout<<mat[i][j]<<" ";
		// 	cout<<endl;
		// }
		// cout<<endl;
		// for(int i = 0; i < n*m; i++) {
		// 	for(int j = 0; j < 5; j++)
		// 		cout<<tim[i][j]<<" ";
		// 	cout<<endl;
		// }
		while(!pq.empty()) {
			ii p = pq.top(); pq.pop();
			int u = p.ss; int d = p.ff;
			if(d > dis[u])
				continue;
			for(int i = 0; i < n*m; i++) {
				if(mat[u][i]!=inf && d+mat[u][i] < dis[i]) {
					if(tim[i][d+mat[u][i]]) {
						// cout<<i<<" "<<d+mat[u][i]<<endl;
						for(int j = d+mat[u][i]; j<510; j++) {
							// cout<<i<<" na hoga ye "<<j<<" "<<tim[i][j]<<endl;
							if(!tim[i][j]) {
								// cout<<j<<" balle"<<endl;
								dis[i]=j;
								break;
							}
						}
					}
					else dis[i]=d+mat[u][i];
					pq.push({dis[i], i});
				}
			}
		}
		// for(int i = 0; i < n*m; i++)
		// 	cout<<dis[i]<<" ";
		// cout<<endl;
		cout<<dis[n*m-1]<<endl;
	}
	time();	
	return 0;
}