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
int val[110], n, m;
int32_t main(void)
{
	IOS;
	int t, tc=0; cin>>t;
	while(++tc<=t) {
		cin>>n>>m;
		vector<vi> adjlist(n);
		for(int i = 0; i < n; i++)
			cin>>val[i];
		for(int i = 0; i < m; i++) {
			int u, v; cin>>u>>v;
			adjlist[u].pb(v);
		}
		int node=0, ans=val[node], vc=0;
		while(adjlist[node].size()!=0) {
			int mx=0, mxi=-1;
			for(int i = 0; i < adjlist[node].size(); i++) {
				if(mx < val[adjlist[node][i]]) {
					mxi=adjlist[node][i]; 
					mx=val[adjlist[node][i]];
				}
			}
			// cout<<mx<<" "<<mxi<<" "<<ans<<endl;
			ans+=mx; vc=mxi;
			node=mxi;
		}
		cout<<"Case "<<tc<<": "<<ans<<" "<<vc<<endl;
	}
	return 0;
}