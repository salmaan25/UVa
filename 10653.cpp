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
int dx[] = {1, -1, 0, 0}, dy[]={0, 0 , 1, -1};
int32_t main(void)
{
	IOS;
	int r, c; cin>>r>>c;
	while(!(!r  && !c)) {
		int nbr; cin>>nbr;
		int mat[r][c];
		for(int i = 0; i < r; i++) {
			for(int j = 0; j < c; j++)
				mat[i][j]=1;
		}
		for(int i = 0; i < nbr; i++) {
			int rn, ct;
			cin>>rn>>ct;
			for(int j = 0; j < ct; j++) {
				int cn; cin>>cn;
				mat[rn][cn]=0;
			}
		}
		// for(int i = 0; i < r; i++) {
		// 	for(int j = 0; j < c; j++)
		// 		cout<<mat[i][j]<<" ";
		// 	cout<<endl;	
		// }
		ii st, end;
		cin>>st.ff>>st.ss>>end.ff>>end.ss;
		int vis[r][c];
		for(int i = 0; i < r; i++) {
			for(int j = 0; j < c; j++)
				vis[i][j]=inf;
		}
		vis[st.ff][st.ss]=0;
		queue<ii> q; q.push(st);
		while(!q.empty()) {
			ii p = q.front(); q.pop();
			for(int j = 0; j < 4; j++) {
				int rn=p.ff+dx[j], cn = p.ss+dy[j];
				if(rn<r && rn>=0 && cn<c && cn>=0 && mat[rn][cn] && vis[rn][cn]==inf) {
					vis[rn][cn]=min(vis[rn][cn], vis[p.ff][p.ss]+1);
					q.push({rn, cn});
				}
			}
		}
		cout<<vis[end.ff][end.ss]<<endl;
		cin>>r>>c;
	}
	time();	
	return 0;
}