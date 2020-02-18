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
int n;
int mat[110][110];
int he[110][110];
int vis[110][110];
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
void dfs(int r, int c, int* ch) {
	vis[r][c]=1;
	if(!he[r][c])
		*ch=1;
	for(int i = 0; i < 4; i++) {
		int rn = r+dx[i], cn = c+dy[i];
		if(rn<n && cn<n && rn>=0 && cn>=0) {
			if(mat[rn][cn] && !vis[rn][cn])
				dfs(rn, cn, ch);
		}
	}
}
int32_t main(void)
{
	IOS;
	int t, tc=0; cin>>t;
	while(++tc<=t) {
		cin>>n;
		memset(mat, 0, sizeof(mat));
		memset(he, 0, sizeof(he));
		memset(vis, 0, sizeof(vis));
		for(int i = 0; i < n; i++) {
			string s; cin>>s;
			for(int j = 0; j < s.length(); j++) {
				if(s[j]=='x' || s[j]=='@')
					mat[i][j]=1;
				else mat[i][j]=0;
				if(s[j]=='@')
					he[i][j]=1;
			}
		}
		int l=0;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				if(!vis[i][j] && mat[i][j]) {
					int ch=0;
					dfs(i, j, &ch);
					if(ch)
						l++;
				}
			}
		}
		cout<<"Case "<<tc<<": "<<l<<endl;
	}
	time();	
	return 0;
}