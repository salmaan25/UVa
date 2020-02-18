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
	int n, m; cin>>n>>m;
	while(!(!n && !m)) {
		int mat[n+1][m+1];
		for(int i = 0; i <= n; i++) {
			for(int j = 0; j <= m; j++)
				mat[i][j]=1;
		}
		vector<vi> adjlist((n+1)*(m+1)*4);
		for(int i = 0 ; i <= n; i++) {
			mat[i][0]=0; mat[i][m]=0;
		}
		for(int i = 0 ; i <= m; i++) {
			mat[0][i]=0; mat[n][i]=0;
		}
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				int b; cin>>b;
				if(b==1) {
					mat[i][j]=0; mat[i+1][j]=0;
					mat[i][j+1]=0; mat[i+1][j+1]=0;
				}
			}
		}
		for(int i = 0; i <= n; i++) {
			for(int j = 0; j <= m; j++) {
				if(!mat[i][j]) continue;
				int nt=(i*m+j)*4;
				adjlist[nt].pb(nt+1); adjlist[nt].pb(nt+3);
				adjlist[nt+1].pb(nt); adjlist[nt+1].pb(nt+2);
				adjlist[nt+2].pb(nt+1); adjlist[nt+2].pb(nt+3);
				adjlist[nt+3].pb(nt); adjlist[nt+3].pb(nt+2);
				int f1=0, f2=0, f3=0, f4=0;
				for(int k = 1; k <= 3; k++) {
					if(i-k >= 0 && i-k <= n && !f1) {
						if(!mat[i-k][j]) f1=1;
						else adjlist[nt].pb(((i-k)*m+j)*4);
					}
					if(i+k >= 0 && i+k <= n && !f2) {
						if(!mat[i+k][j]) f2=1;
						else adjlist[nt+2].pb((((i+k)*m+j)*4)+2);
					}
					if(j+k >= 0 && j+k <= m && !f3) {
						// if(i == 2 && j == 2) cout<<"kmfmfkdv "<<k<<" "<<mat[i][j+k]<<endl;
						if(!mat[i][j+k]) f3=1;
						else adjlist[nt+1].pb(((i*m+j+k)*4)+1);
					}
					if(j-k >= 0 && j-k <= m && !f4)  {
						if(!mat[i][j-k]) f4=1;
						else adjlist[nt+3].pb(((i*m+j-k)*4)+3);
					}
				}			
			}
		}
		ii st, end; string dn; int on;
		cin>>st.ff>>st.ss>>end.ff>>end.ss>>dn;
		if(dn=="north") on=0;
		else if(dn=="south") on=2;
		else if(dn=="east") on=1;
		else on=3;
		queue<pair<ii, int>> q;
		vi vis((n+1)*(m+1)*4, inf);
		vis[(st.ff*m+st.ss)*4+on]=0;
		q.push({st, on});
		while(!q.empty()) {
			pair<ii, int> p = q.front(); q.pop();
			int u = (p.ff.ff*m+p.ff.ss)*4+p.ss;
			for(int i = 0; i < adjlist[u].size(); i++) {
				int v = adjlist[u][i];
				if(vis[v]!=inf)
					continue;
				int r, c, ddn;
				r = (v/4)/m; c = (v/4)-(r*m);
				ddn = v-((r*m+c)*4);
				
				if(mat[r][c]!=0) {
					vis[v]=vis[u]+1;
					q.push({{r,c}, ddn});			
				}
			}
		}
		int fn = (end.ff*m+end.ss)*4;
		int mn = min(vis[fn], min(vis[fn+1], min(vis[fn+2], vis[fn+3])));
		if(mn >= inf) cout<<-1<<endl;
		else cout<<mn<<endl;
		cin>>n>>m;
	}
	time();	
	return 0;
}